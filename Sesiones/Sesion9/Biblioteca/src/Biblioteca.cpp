#include "../includes/Biblioteca.hpp"
#include <iostream>

void Biblioteca::agregarLibro(const std::string &titulo,
                              const std::string &autor) {
  this->catalogo.emplace_back(
      titulo,
      autor); // Método emplace_back crea el objeto y lo guarda al final;
};

void Biblioteca::mostrarCatalogo() const {
  for (const auto &libro : catalogo) {
    libro.mostrarInfo();
  }
}
