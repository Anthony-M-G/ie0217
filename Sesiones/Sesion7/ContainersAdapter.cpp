#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> pila; // Crea una pila de enteros

  pila.push(1); // Agrega un elemento a la pila
  pila.push(2);
  pila.push(3);
  pila.push(4);

  cout << "Pila: " << endl;

  while (!pila.empty()) // Mientras la pila no esté vacía
  {
    cout << pila.top() << endl; // Muestra el elemento de arriba de la pila
    pila.pop();
  }

  return 0;
}