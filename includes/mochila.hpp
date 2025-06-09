#ifndef MOCHILA_HPP
#define MOCHILA_HPP

#include <vector>
#include <string>

struct Producto {
    int id;
    int peso;
    int volumen;
    int valor;
};

class Mochila {
public:
    void cargarProductos(const std::string& archivo);
    void cargarProductosFiltrados(const std::string& archivo, const std::vector<int>& idsPermitidos);
    int resolver(int capacidadPeso, int capacidadVolumen);
private:
    std::vector<Producto> productos;
};

#endif
