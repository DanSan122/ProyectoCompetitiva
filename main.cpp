#include "includes/almacen.hpp"
#include "includes/mochila.hpp"
#include "includes/rutas.hpp"
#include "includes/utils.hpp"
#include <iostream>
using namespace std;

int main() {
    auto pedidos = leerPedidos("data/pedidos.csv");

    for (const auto& [pedidoId, productos] : pedidos) {
        cout << "\n--- Pedido #" << pedidoId << " ---\n";

        // Almacén
        Almacen almacen;
        almacen.cargarMapa("data/mapa_almacen.txt");

        // Simulamos recorrido falso para la demo de animación:
        vector<pair<int, int>> recorrido = almacen.obtenerRecorrido(productos);
        almacen.mostrarMapaAnimado(recorrido);


        // Mochila
        Mochila mochila;
        mochila.cargarProductosFiltrados("data/productos.csv", productos);
        int resultado = mochila.resolver(50, 100);
        cout << "Valor total cargado: " << resultado << "\n";

        // Rutas
        Rutas rutas;
        rutas.cargarGrafo("data/rutas.txt");
        auto camino = rutas.dijkstra(0);
        cout << "Rutas óptimas desde nodo 0: ";
        for (int d : camino) cout << d << " ";
        cout << "\n";
    }

    return 0;
}
