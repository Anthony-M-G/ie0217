#include "../includes/Producto.hpp"

Producto::Producto() {
  this->id = 0;
  this->nombre = "";
  this->precio = 0.0;
  this->cantidad = 0;
}

Producto::Producto(std::string nombre, double precio, int cantidad) {
  this->nombre = nombre;
  this->precio = precio;
  this->cantidad = cantidad;
}

int Producto::getId() const { return this->id; }

std::string Producto::getNombre() const { return this->nombre; }

float Producto::getPrecio() const { return this->precio; }

int Producto::getCantidad() const { return this->cantidad; }

void Producto::setId(int id) { this->id = id; }

void Producto::setNombre(std::string nombre) { this->nombre = nombre; }

void Producto::setPrecio(float precio) { this->precio = precio; }

void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }

std::ostream &operator<<(std::ostream &os, const Producto &producto) {
  os << "ID: " << producto.id << std::endl;
  os << "Nombre: " << producto.nombre << std::endl;
  os << "Precio: " << producto.precio << std::endl;
  os << "Cantidad: " << producto.cantidad << std::endl;
  return os;
}