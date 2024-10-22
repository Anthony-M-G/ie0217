#include "../../includes/entidades/Curso.h"

Curso::Curso() {} // Constructor por defecto

Curso::Curso(int id_curso, const std::string &nombre_curso, int id_profesor)
    : id_curso(id_curso), nombre_curso(nombre_curso),
      id_profesor(id_profesor) { // Constructor parametrizado
}

Curso::~Curso() {}

int Curso::getIdCurso() const {
  return this->id_curso;
} // Obtiene el ID del curso

void Curso::setIdCurso(int id_curso) {
  this->id_curso = id_curso;
} // Establece el ID del curso

std::string Curso::getNombreCurso() const {
  return this->nombre_curso;
} // Obtiene el nombre del curso

void Curso::setNombreCurso(const std::string &nombre_curso) {
  this->nombre_curso = nombre_curso;
}

int Curso::getIdProfesor() const { return this->id_profesor; }

void Curso::setIdProfesor(int id_profesor) { this->id_profesor = id_profesor; }

std::ostream &
operator<<(std::ostream &os,
           const Curso &curso) { // Sobrecarga del operador de inserción
  os << "ID Curso: " << curso.id_curso << std::endl;
  os << "Nombre Curso: " << curso.nombre_curso << std::endl;
  os << "ID Profesor: " << curso.id_profesor << std::endl;
  return os;
}