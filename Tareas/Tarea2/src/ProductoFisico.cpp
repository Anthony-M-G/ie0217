#include "../includes/ProductoFisico.hpp"
// Implementación de la clase ProductoFisico
ProductoFisico::ProductoFisico(const string &t_nombre, double t_precio, double t_peso) : Producto(t_nombre, t_precio), peso(t_peso) {}

void ProductoFisico::setPeso(double t_peso)
{
  this->peso = t_peso;
}

double ProductoFisico::getPeso() const
{
  return this->peso;
}

void ProductoFisico::mostrarInformacion() const // Método que muestra la información de un producto físico utilizando la sobrecarga del operador de << declarada en Producto.hpp
{
  cout << *this << " Peso: " << peso << " Tipo de producto: Producto Fisico" << endl;
}
