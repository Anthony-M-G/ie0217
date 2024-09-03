#include "../includes/Producto.hpp"
// Implementación de la clase Producto
Producto::Producto(const string &t_nombre, double t_precio) : nombre(t_nombre), precio(t_precio) {} // Constructor de la clase Producto

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

// Sobrecarga del operador de << para mostrar la información de un producto, esta función es la implementación de la función amiga declarada en Producto.hpp
ostream &operator<<(ostream &os, const Producto &producto)
{
  os << "Nombre: " << producto.nombre << " Precio: " << producto.precio;
  return os;
}
