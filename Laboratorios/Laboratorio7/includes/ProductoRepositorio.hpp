#ifndef PRODUCTOREPOSITORIO_HPP
#define PRODUCTOREPOSITORIO_HPP
// Clase abstracta ProductoRepositorio que define los métodos que deben ser
// implementados por las clases que la hereden, es decir como una interfaz
#include "Producto.hpp"

class ProductoRepositorio {
public:
  virtual void guardarProducto(Producto &prod) = 0;
  virtual void actualizarProducto(int id, std::string nombre, float precio,
                                  int cantidad) = 0;
  virtual void eliminarProducto(int id) = 0;
  virtual void mostrarProductos() = 0;

  virtual ~ProductoRepositorio() {}

protected:
  ProductoRepositorio() {}
};

#endif // PRODUCTOREPOSITORIO_HPP