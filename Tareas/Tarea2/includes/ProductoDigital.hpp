#ifndef PRODUCTO_DIGITAL_HPP
#define PRODUCTO_DIGITAL_HPP

#include "Producto.hpp"
#include <iostream>

class ProductoDigital : public Producto
{
private:
  int id;

public:
  ProductoDigital(int t_id, const string &t_nombre, double t_precio);

  void setId(int t_id);

  int getId() const;

  void mostrarInformacion() const override;
};

#endif