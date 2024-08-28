#include "../includes/Producto.hpp"
#include <iostream>
using namespace std;

Producto::Producto(const string &t_nombre, double t_precio) : nombre(t_nombre), precio(t_precio) {}

void Producto::setPrecio(double t_precio)
{
  this->precio = t_precio;
}

void Producto::setNombre(const string &t_nombre)
{
  this->nombre = t_nombre;
}

double Producto::getPrecio() const
{
  return this->precio;
}

string Producto::getNombre() const
{
  return this->nombre;
}

ostream &operator<<(ostream &os, const Producto &producto)
{
  os << "Nombre: " << producto.nombre << " Precio: " << producto.precio;
  return os;
}
