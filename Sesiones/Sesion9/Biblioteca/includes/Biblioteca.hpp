#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "Libro.hpp"
#include <string>
#include <vector>
class Biblioteca {
public:
  void agregarLibro(const std::string &titulo, const std::string &autor);
  void mostrarCatalogo() const;

private:
  std::vector<Libro> catalogo;
};

#endif
