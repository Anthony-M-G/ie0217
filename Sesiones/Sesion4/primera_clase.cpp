#include <iostream>
using namespace std;
// Este es el boilerplate de una clase en C++ es decir la estructura basica de una clase
class Molde
{
public:
  double largo;
  double ancho;
  double alto;

  Molde(double t_largo, double t_ancho, double t_alto) // Constructor de la clase
  {
    largo = t_largo;
    ancho = t_ancho;
    alto = t_alto;
    cout << "Se ha creado un objeto de la clase Molde" << endl;
  }
  ~Molde()
  {
    cout << "Se ha destruido un objeto de la clase Molde" << endl;
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
  Molde pared(10.0, 20.0, 35.0); // Instancia de la clase Molde llamada pared

  cout << "El area de la pared es: " << pared.calcularArea() << endl;
  cout << "El volumen de la pared es: " << pared.calcularVolumen() << endl;

  return 0;
}