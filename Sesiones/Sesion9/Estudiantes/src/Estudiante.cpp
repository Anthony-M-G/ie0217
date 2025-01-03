#include "Estudiante.hpp"
#include <iostream>

Estudiante::Estudiante(const std::string &nombre, int edad)
    : nombre(nombre), edad(edad) {}

void Estudiante::mostrarDatos() const {
  std::cout << this->nombre << " " << this->edad << std::endl;
}

Estudiante::~Estudiante(){};
