#include "rutas.hpp"
#include <fstream>
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

void Rutas::cargarGrafo(const string& archivo) {
    ifstream in(archivo);
    int n;
    in >> n;
    grafo.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            in >> grafo[i][j];
}

vector<int> Rutas::dijkstra(int inicio) {
    int n = grafo.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[inicio] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < n; ++v) {
            if (grafo[u][v] > 0 && dist[v] > dist[u] + grafo[u][v]) {
                dist[v] = dist[u] + grafo[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
