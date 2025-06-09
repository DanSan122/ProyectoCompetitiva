#ifndef RUTAS_HPP
#define RUTAS_HPP

#include <vector>
#include <string>

class Rutas {
public:
    void cargarGrafo(const std::string& archivo);
    std::vector<int> dijkstra(int inicio);
private:
    std::vector<std::vector<int>> grafo;
};

#endif
