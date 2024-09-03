#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include <string>
#include <iostream>
using namespace std;
// Clase Producto
class Producto
{
private:
  string nombre;
  double precio;

public:
  Producto(const string &t_nombre, double t_precio); // Constructor de la clase Producto

  void setPrecio(double t_precio);

  void setNombre(const string &t_nombre);

  double getPrecio() const;

  string getNombre() const;

  virtual ~Producto() = default;

  friend ostream &operator<<(ostream &os, const Producto &producto); // Sobrecarga del operador de << para mostrar la información de un producto

  virtual void mostrarInformacion() const = 0; // Método virtual puro que muestra la información de un producto
};
#endif