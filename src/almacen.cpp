#include "../includes/almacen.hpp"
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;

void Almacen::cargarMapa(const string& archivo) {
    ifstream in(archivo);
    in >> filas >> columnas;
    mapa.resize(filas, vector<char>(columnas));
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            in >> mapa[i][j];
}

void Almacen::mostrarMapa() const {
    for (const auto& fila : mapa) {
        for (char c : fila)
            cout << c << ' ';
        cout << endl;
    }
}

void Almacen::mostrarMapaAnimado(const vector<pair<int, int>>& recorrido) {
    for (size_t paso = 0; paso < recorrido.size(); ++paso) {
        int x = recorrido[paso].first;
        int y = recorrido[paso].second;

        vector<vector<char>> temp = mapa;

        for (size_t i = 0; i <= paso; ++i) {
            int px = recorrido[i].first;
            int py = recorrido[i].second;
            if (temp[px][py] == 'P') temp[px][py] = '.';
            else if (temp[px][py] == '.') temp[px][py] = '*';
        }

        temp[x][y] = 'D';

        system("clear");
        cout << "Paso " << paso + 1 << "/" << recorrido.size() << endl;
        for (const auto& fila : temp) {
            for (char c : fila)
                cout << c << ' ';
            cout << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

vector<pair<int, int>> bfs(const vector<vector<char>>& mapa, pair<int, int> start, pair<int, int> goal) {
    int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
    int rows = mapa.size(), cols = mapa[0].size();
    queue<pair<int, int>> q;
    map<pair<int, int>, pair<int, int>> parent;
    set<pair<int, int>> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x,y) == goal) break;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            pair<int, int> next = {nx, ny};
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                mapa[nx][ny] != '#' && visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
                parent[next] = {x, y};
            }
        }
    }

    vector<pair<int, int>> path;
    pair<int, int> current = goal;
    if (parent.find(current) == parent.end()) return {}; // no path
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int, int>> Almacen::obtenerRecorrido(const vector<int>& productos) {
    map<int, pair<int, int>> ubicacionProductos;
    pair<int, int> inicio = {-1, -1};

    // encontrar S y P
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j) {
            if (mapa[i][j] == 'S') inicio = {i, j};
            if (mapa[i][j] == 'P') ubicacionProductos[ubicacionProductos.size() + 1] = {i, j};
        }

    vector<pair<int, int>> recorrido;
    pair<int, int> actual = inicio;
    for (int id : productos) {
        if (ubicacionProductos.count(id) == 0) continue;
        auto tramo = bfs(mapa, actual, ubicacionProductos[id]);
        if (tramo.empty()) continue;
        recorrido.insert(recorrido.end(), tramo.begin(), tramo.end());
        actual = ubicacionProductos[id];
    }

    return recorrido;
}