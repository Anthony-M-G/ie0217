#include "../includes/Cliente.hpp"

/**
 * @class Cliente
 * @brief Representa un cliente en la tienda.
 *
 * La clase `Cliente` gestiona la información del cliente y su carrito de compras. Permite agregar productos al carrito,
 * calcular el total de la compra aplicando descuentos y obtener el nombre del cliente.
 */
Cliente::Cliente(const string &t_nombre) : nombre(t_nombre) {}

/**
 * @brief Obtiene el carrito de compras del cliente.
 *
 * Este método devuelve un vector de punteros a objetos `Producto` que representa el carrito de compras del cliente.
 *
 * @return Un vector de punteros a objetos `Producto` que representa el carrito de compras del cliente.
 */
vector<Producto *> Cliente::getCarrito() const
{
  return this->carrito;
}

/**
 * @brief Agrega un producto al carrito de compras del cliente.
 *
 * Este método añade un producto al carrito de compras del cliente. El producto se pasa como un puntero a objeto `Producto`.
 *
 * @param t_producto Puntero al objeto `Producto` que se va a agregar al carrito.
 */
void Cliente::agregarProducto(Producto *t_producto)
{
  this->carrito.push_back(t_producto);
}

/**
 * @brief Calcula el total de los productos en el carrito y aplica el descuento.
 *
 * Este método recorre todos los productos en el carrito, calcula el total de sus precios y aplica un descuento
 * específico según el tipo de cliente. El precio total final se muestra en la consola.
 *
 * @see aplicarDescuento() para obtener el porcentaje de descuento aplicado.
 */
void Cliente::calcularTotal() const
{
  double total = 0;
  double descuento = this->aplicarDescuento(); // Aplicar el descuento según el tipo de cliente

  for (auto &&prod : this->carrito)
  {
    total += prod->getPrecio();
  }
  if (descuento == 0 || descuento == 1)
  {
    cout << "El precio total es: " << total << endl;
    cout << "No se aplicó descuento" << endl;
  }
  else
  {
    total *= (1 - descuento); // Aplicar el descuento al total final
    cout << "El precio total es: " << total << endl;
  }
}

/**
 * @brief Obtiene el nombre del cliente.
 *
 * Este método devuelve el nombre del cliente.
 *
 * @return El nombre del cliente.
 */
string Cliente::getNombre() const
{
  return this->nombre;
}
