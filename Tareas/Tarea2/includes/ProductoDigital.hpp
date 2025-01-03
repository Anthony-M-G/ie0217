#ifndef PRODUCTO_DIGITAL_HPP
#define PRODUCTO_DIGITAL_HPP

#include "Producto.hpp"
#include <iostream>
// Clase ProductoDigital que hereda de Producto
class ProductoDigital : public Producto
{
private:
  int id; // Atributo propio de la clase ProductoDigital

public:
  ProductoDigital(int t_id, const string &t_nombre, double t_precio);

  void setId(int t_id);

  int getId() const;

  void mostrarInformacion() const override;
};

#endif