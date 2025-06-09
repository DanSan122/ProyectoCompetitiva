#include "mochila.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

void Mochila::cargarProductos(const string& archivo) {
    ifstream in(archivo);
    string linea;
    getline(in, linea); // Encabezado

    Producto p;
    while (getline(in, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string idStr, pesoStr, volStr, valStr;

        if (!getline(ss, idStr, ',') ||
            !getline(ss, pesoStr, ',') ||
            !getline(ss, volStr, ',') ||
            !getline(ss, valStr, ',')) continue;

        try {
            p.id = stoi(idStr);
            p.peso = stoi(pesoStr);
            p.volumen = stoi(volStr);
            p.valor = stoi(valStr);
        } catch (...) {
            continue;
        }

        productos.push_back(p);
    }
}

void Mochila::cargarProductosFiltrados(const string& archivo, const vector<int>& ids) {
    productos.clear();
    cargarProductos(archivo);

    vector<Producto> filtrados;
    for (const auto& p : productos) {
        if (find(ids.begin(), ids.end(), p.id) != ids.end())
            filtrados.push_back(p);
    }
    productos = filtrados;
}

int Mochila::resolver(int capacidadPeso, int capacidadVolumen) {
    vector<vector<int>> dp(capacidadPeso + 1, vector<int>(capacidadVolumen + 1, 0));
    for (const auto& p : productos) {
        for (int w = capacidadPeso; w >= p.peso; --w) {
            for (int v = capacidadVolumen; v >= p.volumen; --v) {
                dp[w][v] = max(dp[w][v], dp[w - p.peso][v - p.volumen] + p.valor);
            }
        }
    }
    return dp[capacidadPeso][capacidadVolumen];
}
