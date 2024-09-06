#include "../includes/ProductoFisico.hpp"

/**
 * @class ProductoFisico
 * @brief Representa un producto físico en la tienda.
 *
 * La clase `ProductoFisico` hereda de `Producto` e incluye un peso específico para los productos físicos.
 */
ProductoFisico::ProductoFisico(const string &t_nombre, double t_precio, double t_peso) : Producto(t_nombre, t_precio), peso(t_peso) {}

/**
 * @brief Establece el peso del producto físico.
 *
 * Este método permite actualizar el peso del producto físico.
 *
 * @param t_peso Nuevo peso del producto físico.
 */
void ProductoFisico::setPeso(double t_peso)
{
  this->peso = t_peso;
}

/**
 * @brief Obtiene el peso del producto físico.
 *
 * Este método devuelve el peso actual del producto físico.
 *
 * @return El peso del producto físico.
 */
double ProductoFisico::getPeso() const
{
  return this->peso;
}

/**
 * @brief Muestra la información del producto físico.
 *
 * Este método imprime la información del producto físico en la consola, incluyendo el nombre, el precio, el peso y el tipo de producto.
 * Utiliza la sobrecarga del operador de inserción (<<) definida en la clase Producto para mostrar el nombre y el precio.
 */
void ProductoFisico::mostrarInformacion() const
{
  cout << *this << " Peso: " << peso << " Tipo de producto: Producto Fisico" << endl;
}
