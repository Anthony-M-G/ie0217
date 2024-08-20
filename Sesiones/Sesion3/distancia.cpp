#include <iostream>
using namespace std;

struct Distancia
{
  int pies;
  float pulgadas;
};

int main()
{
  Distancia *ptr, d;

  ptr = &d;

  cout << "Ingrese pies: ";
  cin >> (*ptr).pies;
  cout << "Ingrese pulgadas: ";
  cin >> (*ptr).pulgadas;

  cout << "Mostrando información." << endl;
  cout << "Distancia = " << (*ptr).pies << " pies " << (*ptr).pulgadas << " pulgadas" << endl;

  // Usando la notación de flecha
  cout << "\nUsando la notación de flecha" << endl;

  cout << "Mostrando información." << endl;
  cout << "ptr->pies: " << ptr->pies << " ptr->pulgadas: " << ptr->pulgadas << endl;

  return 0;
}
