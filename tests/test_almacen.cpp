#include "../includes/almacen.hpp"
#include <iostream>
using namespace std;

int main() {
    Almacen a;
    a.cargarMapa("../data/mapa_almacen.txt");
    a.mostrarMapa();
    return 0;
}
