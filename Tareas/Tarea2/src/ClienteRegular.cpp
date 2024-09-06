#include "../includes/ClienteRegular.hpp"

/**
 * @class ClienteRegular
 * @brief Representa un cliente regular en la tienda sin descuento aplicable.
 *
 * La clase `ClienteRegular` hereda de `Cliente` y representa un cliente que no recibe descuentos en sus compras.
 */
ClienteRegular::ClienteRegular(const string &t_nombre) : Cliente(t_nombre) {}

/**
 * @brief Obtiene el porcentaje de descuento aplicable para el cliente regular.
 *
 * Este método devuelve el porcentaje de descuento que se aplica a los productos comprados por el cliente regular.
 * En el caso de un cliente regular, el descuento aplicado es del 0%, por lo que el valor devuelto es 1, indicando que no se aplica descuento.
 *
 * @return El porcentaje de descuento como un valor decimal (1 para 0% de descuento).
 */
double ClienteRegular::aplicarDescuento() const
{
  return 1;
}
