#include "../includes/Tienda.hpp"

/**
 * @class Tienda
 * @brief Representa una tienda que gestiona productos y clientes.
 *
 * La clase `Tienda` administra una lista de productos y clientes. Permite agregar productos y clientes, y procesar compras para clientes específicos.
 */
Tienda::Tienda() {}

/**
 * @brief Destructor de la clase Tienda.
 *
 * Libera la memoria asignada a los productos y clientes en la tienda. Se asegura de eliminar todos los objetos `Producto` y `Cliente` creados dinámicamente para evitar fugas de memoria.
 */
Tienda::~Tienda()
{
  for (auto producto : productosDisponibles)
  {
    delete producto;
  }
  for (auto cliente : clientes)
  {
    delete cliente;
  }
}

/**
 * @brief Obtiene la lista de productos disponibles en la tienda.
 *
 * @return Un vector de punteros a objetos `Producto` que representa los productos disponibles en la tienda.
 */
vector<Producto *> Tienda::getProductosDisponibles() const
{
  return this->productosDisponibles;
}

/**
 * @brief Obtiene la lista de clientes de la tienda.
 *
 * @return Un vector de punteros a objetos `Cliente` que representa los clientes registrados en la tienda.
 */
vector<Cliente *> Tienda::getClientes() const
{
  return this->clientes;
}

/**
 * @brief Agrega un producto a la tienda.
 *
 * Este método permite agregar un nuevo producto a la lista de productos disponibles en la tienda.
 *
 * @param producto Puntero al objeto `Producto` que se va a agregar a la tienda.
 */
void Tienda::agregarProducto(Producto *producto)
{
  this->productosDisponibles.push_back(producto);
}

/**
 * @brief Agrega un cliente a la tienda.
 *
 * Este método permite agregar un nuevo cliente a la lista de clientes registrados en la tienda.
 *
 * @param cliente Puntero al objeto `Cliente` que se va a agregar a la tienda.
 */
void Tienda::agregarCliente(Cliente *cliente)
{
  this->clientes.push_back(cliente);
}

/**
 * @brief Procesa la compra para un cliente específico.
 *
 * Busca al cliente por su nombre, muestra los productos en el carrito del cliente y calcula el total con el descuento aplicable, si corresponde.
 *
 * @param name Nombre del cliente para el cual se procesará la compra.
 *
 * Si el cliente no se encuentra en la lista de clientes, se muestra un mensaje de error.
 */
void Tienda::procesarCompra(const string &name) const
{
  bool clienteEncontrado = false;

  // Buscar al cliente por su nombre
  for (auto &&cliente : this->clientes)
  {
    if (cliente->getNombre() == name)
    {
      clienteEncontrado = true;
      cout << "Procesando compra para el cliente: " << cliente->getNombre() << endl;
      cout << "Productos en el carrito: " << endl;

      // Mostrar los productos en el carrito del cliente
      for (auto &&producto : cliente->getCarrito())
      {
        producto->mostrarInformacion(); // Asegúrate de que cada clase hija de Producto tenga este método
      }

      // Calcular el total con el descuento, si aplica
      cliente->calcularTotal();
    }
  }

  // Si no se encontró al cliente, mostrar un mensaje de error
  if (!clienteEncontrado)
  {
    cout << "Cliente no encontrado: " << name << endl;
  }
}
