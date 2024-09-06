#include "includes/Producto.hpp"
#include "includes/ProductoDigital.hpp"
#include "includes/ProductoFisico.hpp"
#include "includes/Cliente.hpp"
#include "includes/ClienteRegular.hpp"
#include "includes/ClientePremium.hpp"
#include "includes/Tienda.hpp"
#include <iostream>
#include <vector>

// Enum para las opciones del menú principal
enum class MenuOption
{
  AgregarProducto = 1,
  RegistrarCliente,
  AgregarProductoAlCarrito,
  ProcesarCompra,
  Salir
};

// Enum para los tipos de producto
enum class ProductoType
{
  Digital = 1,
  Fisico
};

// Enum para los tipos de cliente
enum class ClienteType
{
  Regular = 1,
  Premium
};

int main(int argc, char const *argv[])
{
  Tienda tienda;
  MenuOption opcion;

  do
  {
    std::cout << "\nMenú Tienda Virtual\n";
    std::cout << "1. Agregar producto\n";
    std::cout << "2. Registrar cliente\n";
    std::cout << "3. Agregar producto al carrito\n";
    std::cout << "4. Procesar compra\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
    int opcionInput;
    std::cin >> opcionInput;
    opcion = static_cast<MenuOption>(opcionInput);

    switch (opcion)
    {
    case MenuOption::AgregarProducto:
    {
      int tipoProductoInput;
      std::string nombre;
      double precio;

      std::cout << "Agregar producto\n";
      std::cout << "1. Producto Digital\n";
      std::cout << "2. Producto Físico\n";
      std::cin >> tipoProductoInput;
      auto tipoProducto = static_cast<ProductoType>(tipoProductoInput);

      std::cout << "Ingrese nombre del producto: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombre);
      std::cout << "Ingrese precio del producto: ";
      std::cin >> precio;

      if (tipoProducto == ProductoType::Digital)
      {
        int id;
        std::cout << "Ingrese el ID del producto digital: ";
        std::cin >> id;
        Producto *productoDigital = new ProductoDigital(id, nombre, precio);
        tienda.agregarProducto(productoDigital);
      }
      else if (tipoProducto == ProductoType::Fisico)
      {
        double peso;
        std::cout << "Ingrese el peso del producto físico: ";
        std::cin >> peso;
        Producto *productoFisico = new ProductoFisico(nombre, precio, peso);
        tienda.agregarProducto(productoFisico);
      }
      break;
    }
    case MenuOption::RegistrarCliente:
    {
      int tipoClienteInput;
      std::string nombre;

      std::cout << "Registrar cliente\n";
      std::cout << "1. Cliente Regular\n";
      std::cout << "2. Cliente Premium\n";
      std::cin >> tipoClienteInput;
      auto tipoCliente = static_cast<ClienteType>(tipoClienteInput);

      std::cout << "Ingrese nombre del cliente: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombre);

      if (tipoCliente == ClienteType::Regular)
      {
        Cliente *clienteRegular = new ClienteRegular(nombre);
        tienda.agregarCliente(clienteRegular);
      }
      else if (tipoCliente == ClienteType::Premium)
      {
        double descuento;
        std::cout << "Ingrese el porcentaje de descuento (ej: 0.25 para 25%): ";
        std::cin >> descuento;
        Cliente *clientePremium = new ClientePremium(nombre, descuento);
        tienda.agregarCliente(clientePremium);
      }
      break;
    }
    case MenuOption::AgregarProductoAlCarrito:
    {
      std::string nombreCliente, nombreProducto;

      std::cout << "Agregar producto al carrito\n";
      std::cout << "Ingrese nombre del cliente: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombreCliente);
      std::cout << "Ingrese nombre del producto: ";
      std::getline(std::cin, nombreProducto);

      // Buscar el cliente por nombre usando getClientes()
      Cliente *cliente = nullptr;
      for (auto &&c : tienda.getClientes())
      {
        if (c->getNombre() == nombreCliente)
        {
          cliente = c;
          break;
        }
      }

      if (cliente == nullptr)
      {
        std::cout << "Cliente no encontrado.\n";
        break;
      }

      // Buscar el producto por nombre usando getProductosDisponibles()
      Producto *producto = nullptr;
      for (auto &&p : tienda.getProductosDisponibles())
      {
        if (p->getNombre() == nombreProducto)
        {
          producto = p;
          break;
        }
      }

      if (producto == nullptr)
      {
        std::cout << "Producto no encontrado.\n";
        break;
      }

      // Agregar el producto al carrito del cliente
      cliente->agregarProducto(producto);
      std::cout << "Producto agregado al carrito del cliente " << nombreCliente << ".\n";
      break;
    }
    case MenuOption::ProcesarCompra:
    {
      std::string nombreCliente;

      std::cout << "Procesar compra\n";
      std::cout << "Ingrese nombre del cliente: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombreCliente);

      tienda.procesarCompra(nombreCliente);
      break;
    }
    case MenuOption::Salir:
      std::cout << "Saliendo del programa...\n";
      break;
    default:
      std::cout << "Opción inválida\n";
    }
  } while (opcion != MenuOption::Salir);

  return 0;
}
