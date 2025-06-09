#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include <vector>
#include <string>
#include <utility>

class Almacen {
public:
    void cargarMapa(const std::string& archivo);
    void mostrarMapa() const;
    void mostrarMapaAnimado(const std::vector<std::pair<int, int>>& recorrido);

    void buscarProductos();
    std::vector<std::pair<int, int>> obtenerRecorrido(const std::vector<int>& productos);


private:
    std::vector<std::vector<char>> mapa;
    int filas = 0, columnas = 0;
};

#endif
