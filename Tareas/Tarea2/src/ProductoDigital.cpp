#include "../includes/ProductoDigital.hpp"

ProductoDigital::ProductoDigital(int t_id, const string &t_nombre, double t_precio) : Producto(t_nombre, t_precio), id(t_id) {}

void ProductoDigital::setId(int t_id)
{
  this->id = t_id;
}

int ProductoDigital::getId() const
{
  return this->id;
}

void ProductoDigital::mostrarInformacion() const
{
  cout << *this << " Tipo de producto: Producto Digital" << endl;
}