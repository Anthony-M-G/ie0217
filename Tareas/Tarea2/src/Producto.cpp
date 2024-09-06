#include "../includes/Producto.hpp"

/**
 * @class Producto
 * @brief Representa un producto en la tienda.
 *
 * La clase `Producto` contiene la información básica de un producto, incluyendo su nombre y precio.
 */
Producto::Producto(const string &t_nombre, double t_precio) : nombre(t_nombre), precio(t_precio) {}

/**
 * @brief Establece el precio del producto.
 *
 * Este método permite actualizar el precio del producto.
 *
 * @param t_precio Nuevo precio del producto.
 */
void Producto::setPrecio(double t_precio)
{
  this->precio = t_precio;
}

/**
 * @brief Establece el nombre del producto.
 *
 * Este método permite actualizar el nombre del producto.
 *
 * @param t_nombre Nuevo nombre del producto.
 */
void Producto::setNombre(const string &t_nombre)
{
  this->nombre = t_nombre;
}

/**
 * @brief Obtiene el precio del producto.
 *
 * Este método devuelve el precio actual del producto.
 *
 * @return El precio del producto.
 */
double Producto::getPrecio() const
{
  return this->precio;
}

/**
 * @brief Obtiene el nombre del producto.
 *
 * Este método devuelve el nombre actual del producto.
 *
 * @return El nombre del producto.
 */
string Producto::getNombre() const
{
  return this->nombre;
}

/**
 * @brief Sobrecarga del operador de inserción para mostrar la información de un producto.
 *
 * Este operador permite utilizar el operador de inserción (<<) para imprimir un objeto `Producto` en una corriente de salida (ostream).
 * La salida mostrará el nombre y el precio del producto.
 *
 * @param os La corriente de salida (ostream) donde se imprimirá la información del producto.
 * @param producto El objeto `Producto` que se imprimirá.
 * @return La corriente de salida (ostream) para permitir la encadenación de operaciones.
 */
ostream &operator<<(ostream &os, const Producto &producto)
{
  os << "Nombre: " << producto.nombre << " Precio: " << producto.precio;
  return os;
}
