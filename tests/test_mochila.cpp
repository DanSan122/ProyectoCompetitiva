#include "../includes/mochila.hpp"
#include <iostream>
using namespace std;

int main() {
    Mochila m;
    m.cargarProductos("data/productos.csv");
    int resultado = m.resolver(50, 100);
    cout << "Resultado mochila: " << resultado << endl;
    return 0;
}
