#include <iostream>
#include <list>
using namespace std;

int main() {
    // Crear una lista de enteros
    list<int> nums {1, 2, 3, 4, 5};

    // Inicializar el iterador para que apunte al inicio de nums
    list<int>::iterator itr = nums.begin();

    // Mostrar el movimiento hacia adelante
    cout << "Moviendo hacia adelante: " << endl;

    // Mostrar los elementos en orden hacia adelante
    while (itr != nums.end()) {
        cout << *itr << ", ";
        // Mover el iterador una posición hacia adelante
        itr++;
    }

    cout << endl << "Moviendo hacia atrás: " << endl;

    // Mostrar los elementos en orden hacia atrás
    while (itr != nums.begin()) {
        // Primero retrocedemos el iterador porque está en end()
        itr--;
        if (itr != nums.end()) {
            cout << *itr << ", ";
        }
    }

    cout << endl;

    return 0;
}
