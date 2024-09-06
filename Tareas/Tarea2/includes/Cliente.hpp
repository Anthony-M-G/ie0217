#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <iostream>
#include <vector>
#include "Producto.hpp"
using namespace std;

class Cliente
{
private:
  string nombre;
  vector<Producto *> carrito;

public:
  Cliente(const string &t_nombre);

  virtual ~Cliente() = default;

  vector<Producto *> getCarrito() const;

  string getNombre() const;

  // Método agregar producto que recibe un producto y lo agrega al carrito
  void agregarProducto(Producto *t_producto);

  // Método para calcular el total de la compra en el carrito
  void calcularTotal() const;

  // Método virtual puro para aplicar el descuento dependiendo de qué tipo de cliente se trata
  virtual double aplicarDescuento() const = 0;
};

#endif