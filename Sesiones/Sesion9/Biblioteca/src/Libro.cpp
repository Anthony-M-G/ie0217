#include "../includes/Libro.hpp"
#include <iostream>
#include <string>
Libro::Libro(const std::string &t_titulo, const std::string &t_autor)
    : titulo(t_titulo), autor(t_autor) {}

void Libro::mostrarInfo() const {
  std::cout << "Titulo: " << this->titulo << " Autor: " << this->autor
            << std::endl;
}
