#ifndef PRODUCTOREPOSITORIOIMPL_HPP
#define PRODUCTOREPOSITORIOIMPL_HPP

#include "Producto.hpp"
#include "ProductoRepositorio.hpp"
#include <sqlite3.h>
#include <vector>

class ProductoRepositorioImpl
    : public ProductoRepositorio { // Clase que hereda de ProductoRepositorio y
                                   // la implementa en su totalidad (clase
                                   // concreta)
private:
  std::vector<Producto> productos;
  sqlite3 *db;

public:
  ProductoRepositorioImpl(sqlite3 *db);
  void guardarProducto(Producto &producto) override;
  void actualizarProducto(int id, std::string nombre, float precio,
                          int cantidad) override;
  void eliminarProducto(int id) override;
  void mostrarProductos() override;

  ~ProductoRepositorioImpl() override;
};

#endif