#include <iostream>
using namespace std;
// Este es el boilerplate de una clase en C++ es decir la estructura basica de una clase
class Molde
{
public:
  double largo;
  double ancho;
  double alto;

  Molde() // Constructor de la clase
  {
    cout << "Se ha creado un objeto de la clase Molde" << endl;
  }

  double calcularArea()
  {
    return largo * ancho;
  }

  double calcularVolumen()
  {
    return largo * ancho * alto;
  }
};

int main()
{
  Molde pared; // Instancia de la clase Molde llamada pared
  pared.largo = 10;
  pared.ancho = 5;
  pared.alto = 3;

  cout << "El area de la pared es: " << pared.calcularArea() << endl;
  cout << "El volumen de la pared es: " << pared.calcularVolumen() << endl;

  return 0;
}