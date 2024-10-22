#include "../../includes/entidades/Profesor.h"

Profesor::Profesor() {}

Profesor::Profesor(int id_profesor, const std::string &nombre,
                   const std::string &escuela)
    : id_profesor(id_profesor), nombre(nombre), escuela(escuela) {
} // Constructor
  // parametrizado

Profesor::~Profesor() {}
// Getters y setters
int Profesor::getIdProfesor() const { return this->id_profesor; }

void Profesor::setIdProfesor(int id_profesor) {
  this->id_profesor = id_profesor;
}

std::string Profesor::getNombre() const { return this->nombre; }

void Profesor::setNombre(const std::string &nombre) { this->nombre = nombre; }

std::string Profesor::getEscuela() const { return this->escuela; }

void Profesor::setEscuela(const std::string &escuela) {
  this->escuela = escuela;
}

std::ostream &operator<<(std::ostream &os, const Profesor &profesor) {
  os << "ID Profesor: " << profesor.id_profesor << std::endl;
  os << "Nombre: " << profesor.nombre << std::endl;
  os << "Escuela: " << profesor.escuela << std::endl;
  return os;
}
