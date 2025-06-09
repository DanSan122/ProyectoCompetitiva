#include "../includes/rutas.hpp"
#include <iostream>
using namespace std;

int main() {
    Rutas r;
    r.cargarGrafo("../data/rutas.txt");
    auto caminos = r.dijkstra(0);
    cout << "Caminos desde nodo 0:" << endl;
    for (int d : caminos)
        cout << d << " ";
    cout << endl;
    return 0;
}
