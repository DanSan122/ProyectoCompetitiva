#include "../includes/utils.hpp"
#include <iostream>
using namespace std;

int main() {
    auto pedidos = leerPedidos("data/pedidos.csv");
    for (const auto& [id, lista] : pedidos) {
        cout << "Pedido #" << id << ": ";
        for (int p : lista) cout << p << ' ';
        cout << endl;
    }
    return 0;
}
