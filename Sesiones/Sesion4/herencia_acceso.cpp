#include <iostream>
using namespace std;

class Animal
{
public:
  void print()
  {
    cout << "Desde la clase base" << endl;
  }
  void setEdad(int age)
  {
    edad = age;
  }

  int getEdad()
  {
    return edad;
  }

protected:
  string nombre;

private:
  int edad;
};

class Perro : public Animal
{
public:
  void print()
  {
    cout << "Desde la clase derivada" << endl;
  }
  void setNombre(string n)
  {
    nombre = n;
  }

  string getNombre()
  {
    return nombre;
  }
};

int main()
{
  Perro perrito;
  perrito.setNombre("Firulais");
  perrito.setEdad(5);

  cout << "El perro " << perrito.getNombre() << " tiene " << perrito.getEdad() << " años." << endl;

  perrito.Animal::print(); // Usa el metodo de la clase base
  perrito.print();         // Usa el metodo de la clase derivada

  return 0;
}