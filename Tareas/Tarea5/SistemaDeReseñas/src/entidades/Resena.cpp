
#include "../../includes/entidades/Resena.h"
#include <iostream>

Resena::Resena() {}

Resena::Resena(int id_profesor, int id_curso, int calificacion,
               int nivel_dificultad, const std::string &comentario)
    : comentario(comentario), calificacion(calificacion),
      id_profesor(id_profesor), id_curso(id_curso),
      calificacion_general(calificacion), nivel_dificultad(nivel_dificultad) {
} // Constructor parametrizado

Resena::~Resena() {}
// Getters y setters
int Resena::getIdResena() const { return id_resena; }

void Resena::setIdResena(int id_resena) { this->id_resena = id_resena; }

std::string Resena::getComentario() { return comentario; }

void Resena::setComentario(const std::string &comentario) {
  this->comentario = comentario;
}

int Resena::getCalificacion() const { return calificacion; }

void Resena::setCalificacion(int calificacion) {
  this->calificacion = calificacion;
}

int Resena::getIdProfesor() const { return id_profesor; }

void Resena::setIdProfesor(int id_profesor) { this->id_profesor = id_profesor; }

int Resena::getIdCurso() const { return id_curso; }

void Resena::setIdCurso(int id_curso) { this->id_curso = id_curso; }

int Resena::getCalificacionGeneral() const { return calificacion_general; }

void Resena::setCalificacionGeneral(int calificacion_general) {
  this->calificacion_general = calificacion_general;
}

int Resena::getNivelDificultad() const { return nivel_dificultad; }

void Resena::setNivelDificultad(int nivel_dificultad) {
  this->nivel_dificultad = nivel_dificultad;
}

bool Resena::getRevisado() const { return revisado; }

void Resena::setRevisado(bool revisado) { this->revisado = revisado; }

std::ostream &operator<<(std::ostream &os, const Resena &resena) {
  os << "ID Reseña: " << resena.id_resena << std::endl;
  os << "Comentario: " << resena.comentario << std::endl;
  os << "Calificación: " << resena.calificacion << std::endl;
  os << "ID Profesor: " << resena.id_profesor << std::endl;
  os << "ID Curso: " << resena.id_curso << std::endl;
  os << "Calificación General: " << resena.calificacion_general << std::endl;
  os << "Nivel de Dificultad: " << resena.nivel_dificultad << std::endl;
  os << "Revisado: " << static_cast<bool>(resena.revisado) << std::endl;
  return os;
}
