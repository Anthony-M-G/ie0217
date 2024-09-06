#include "../includes/ProductoDigital.hpp"

/**
 * @class ProductoDigital
 * @brief Representa un producto digital en la tienda.
 *
 * La clase `ProductoDigital` hereda de `Producto` e incluye un identificador específico para los productos digitales.
 */
ProductoDigital::ProductoDigital(int t_id, const string &t_nombre, double t_precio) : Producto(t_nombre, t_precio), id(t_id) {}

/**
 * @brief Establece el ID del producto digital.
 *
 * Este método permite actualizar el ID del producto digital.
 *
 * @param t_id Nuevo ID del producto digital.
 */
void ProductoDigital::setId(int t_id)
{
  this->id = t_id;
}

/**
 * @brief Obtiene el ID del producto digital.
 *
 * Este método devuelve el ID actual del producto digital.
 *
 * @return El ID del producto digital.
 */
int ProductoDigital::getId() const
{
  return this->id;
}

/**
 * @brief Muestra la información del producto digital.
 *
 * Este método imprime la información del producto digital en la consola, incluyendo el nombre, el precio y el tipo de producto.
 */
void ProductoDigital::mostrarInformacion() const
{
  cout << *this << " Tipo de producto: Producto Digital" << endl;
}
