#include "../includes/ClientePremium.hpp"

/**
 * @class ClientePremium
 * @brief Representa un cliente premium en la tienda con un porcentaje de descuento.
 *
 * La clase `ClientePremium` hereda de `Cliente` y añade la funcionalidad de aplicar un descuento a los precios de los productos
 * que compra el cliente. El descuento se especifica al crear el cliente premium y se aplica en el cálculo total de la compra.
 */
ClientePremium::ClientePremium(const string &t_nombre, double descuento) : Cliente(t_nombre), descuento(descuento) {}

/**
 * @brief Obtiene el porcentaje de descuento aplicable para el cliente premium.
 *
 * Este método devuelve el porcentaje de descuento que se aplica a los productos comprados por el cliente premium.
 * El valor de descuento es un decimal, por ejemplo, 0.25 representa un 25% de descuento.
 *
 * @return El porcentaje de descuento como un valor decimal (ejemplo: 0.25 para un 25% de descuento).
 */
double ClientePremium::aplicarDescuento() const
{
  return this->descuento;
}
