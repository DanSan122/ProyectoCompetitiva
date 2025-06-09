#include "../includes/utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::map<int, std::vector<int>> leerPedidos(const std::string& archivo) {
    std::ifstream in(archivo);
    std::map<int, std::vector<int>> pedidos;
    std::string linea;

    getline(in, linea); // saltar encabezado
    while (getline(in, linea)) {
        std::stringstream ss(linea);
        std::string idStr, productosStr;
        getline(ss, idStr, ',');
        getline(ss, productosStr);

        int pedidoId = std::stoi(idStr);
        std::stringstream ps(productosStr);
        std::vector<int> productos;
        int prod;
        while (ps >> prod) {
            productos.push_back(prod);
        }

        pedidos[pedidoId] = productos;
    }

    return pedidos;
}
