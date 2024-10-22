#include "../../includes/controlador/Controlador.h"

void Controlador::verResenasNoRevisadas()
    const { // Método para ver las reseñas no revisadas
  this->resenaServicio.resenasNoRevisadas();
}

void Controlador::actualizarEstadoDeUnaResena(
    int id_resena) { // Método para actualizar el estado de una reseña
  this->resenaServicio.actualizarEstadoResena(id_resena);
}

void Controlador::cursosPorCalificacionYDificultad(const std::string &escuela)
    const { // Método para ver los cursos por calificación y dificultad
  cursoServicio.cursosPorDificultadYCalificacion(escuela);
}

void Controlador::eliminarResena(
    int id_resena) { // Método para eliminar una reseña
  resenaServicio.eliminarResena(id_resena);
}

void Controlador::profesoresPorCursoYEscuela(const std::string &curso,
                                             const std::string &escuela)
    const { // Método para ver los profesores por curso y escuela
  profesoresServicio.profesorPorCursoYEscuela(curso, escuela);
}

void Controlador::resenasNoRevisadas()
    const { // Método para ver las reseñas no revisadas
  resenaServicio.resenasNoRevisadas();
}

void Controlador::verTodosLosProfesores()
    const { // Método para ver todos los profesores
  profesoresServicio.todosLosProfesores();
}

void Controlador::verTodosLosCursos() const {
  cursoServicio.todosLosCursos();
} // Método para ver todos los cursos

void Controlador::resenasPorCalificacionYDificultad()
    const { // Método para ver las reseñas por calificación y dificultad
  resenaServicio.calificacionYDificultad();
}

void Controlador::verTodasLasResenas()
    const { // Método para ver todas las reseñas
  resenaServicio.verTodasResenas();
}
