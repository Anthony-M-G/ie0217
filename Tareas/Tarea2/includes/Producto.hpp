#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include <string>
using namespace std;

class Producto
{
private:
  string nombre;
  double precio;

public:
  Producto(const string &t_nombre, double t_precio);

  void setPrecio(double t_precio);

  void setNombre(const string &t_nombre);

  double getPrecio() const;

  string getNombre() const;

  virtual ~Producto() = default;

  friend ostream &operator<<(ostream &os, const Producto &Producto);

  virtual void mostrarInformacion() const = 0;
};
#endif