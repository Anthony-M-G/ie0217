#include "Componente.hpp"
#include <iostream>
#include <stdexcept>

// Constructor
Componente::Componente(std::string nombre, std::string categoria, int cantidad,
                       std::string descripcion)
    : nombre(nombre), categoria(categoria), cantidad(cantidad),
      descripcion(descripcion) {}

// Getters
std::string Componente::getNombre() const { return nombre; }
std::string Componente::getCategoria() const { return categoria; }
int Componente::getCantidad() const { return cantidad; }
std::string Componente::getDescripcion() const { return descripcion; }

// Setters
void Componente::setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }

// Métodos
bool Componente::agregarComponente(
    std::map<std::string, Componente> &inventario, const std::string &nombre,
    const std::string &categoria, int cantidad,
    const std::string &descripcion) {
  if (cantidad <= 0) {
    throw std::invalid_argument("La cantidad debe ser mayor a cero.");
    return false;
  }
  if (inventario.find(nombre) != inventario.end()) {
    inventario[nombre].setCantidad(inventario[nombre].getCantidad() + cantidad);
    return true;
  }
  inventario[nombre] = Componente(nombre, categoria, cantidad, descripcion);
  return true;
}

bool Componente::reducirComponente(
    std::map<std::string, Componente> &inventario, const std::string &nombre,
    int cantidad) {
  if (cantidad <= 0)
    throw std::invalid_argument("La cantidad a reducir debe ser mayor a cero.");
  auto it = inventario.find(nombre);
  if (it != inventario.end() && it->second.getCantidad() >= cantidad) {
    it->second.setCantidad(it->second.getCantidad() - cantidad);
    return true;
  } else {
    throw std::runtime_error(
        "Cantidad insuficiente o componente no encontrado.");
  }
}

bool Componente::listarComponentes(
    const std::map<std::string, Componente> &inventario) {
  if (inventario.empty()) {
    throw std::runtime_error("Inventario vacío.");
    return false;
  }
  for (const auto &[nombre, componente] : inventario) {
    std::cout << "Nombre: " << componente.getNombre()
              << ", Categoría: " << componente.getCategoria()
              << ", Cantidad: " << componente.getCantidad()
              << ", Descripción: " << componente.getDescripcion() << "\n";
  }
  return true;
}

bool Componente::buscarComponente(
    const std::map<std::string, Componente> &inventario,
    const std::string &nombre) {
  auto it = inventario.find(nombre);
  if (it != inventario.end()) {
    const Componente &comp = it->second;
    std::cout << "Nombre: " << comp.getNombre()
              << ", Categoría: " << comp.getCategoria()
              << ", Cantidad: " << comp.getCantidad()
              << ", Descripción: " << comp.getDescripcion() << "\n";
    return true;
  } else {
    throw std::runtime_error("Componente no encontrado.");
    return false;
  }
}
