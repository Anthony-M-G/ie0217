#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
// Clase Producto
#include <iostream>
#include <string>

class Producto {
private:
  int id;
  std::string nombre;
  double precio;
  int cantidad;

public:
  Producto();
  Producto(std::string nombre, double precio, int cantidad);
  int getId() const;
  std::string getNombre() const;
  float getPrecio() const;
  int getCantidad() const;
  void setId(int id);
  void setNombre(std::string nombre);
  void setPrecio(float precio);
  void setCantidad(int cantidad);
  void mostrarProducto();

  friend std::ostream &operator<<(std::ostream &os, const Producto &producto);
};

#endif // PRODUCTO_HPP