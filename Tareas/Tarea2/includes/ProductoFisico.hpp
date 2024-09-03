#ifndef PRODUCTO_FISICO_HPP
#define PRODUCTO_FISICO_HPP

#include "Producto.hpp"
// Clase ProductoFisico que hereda de Producto
class ProductoFisico : public Producto
{
private:
  double peso; // Atributo propio de la clase ProductoFisico

public:
  ProductoFisico(const string &t_nombre, double t_precio, double t_peso);

  void setPeso(double t_peso);

  double getPeso() const;

  void mostrarInformacion() const override;
};

#endif