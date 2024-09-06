#ifndef TIENDA_HPP
#define TIENDA_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Producto.hpp"
#include "Cliente.hpp"

using namespace std;

class Tienda
{
private:
  vector<Producto *> productosDisponibles;
  vector<Cliente *> clientes;

public:
  Tienda();

  ~Tienda();

  vector<Producto *> getProductosDisponibles() const;

  vector<Cliente *> getClientes() const;

  void agregarProducto(Producto *producto);

  void agregarCliente(Cliente *cliente);

  void procesarCompra(const string &name) const;
};

#endif