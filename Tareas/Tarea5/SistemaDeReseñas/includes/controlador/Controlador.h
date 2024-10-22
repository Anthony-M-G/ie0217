#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "../servicio/CursoServicio.h"
#include "../servicio/ProfesoresServicio.h"
#include "../servicio/ResenaServicio.h"
#include <iostream>
#include <string>

/**
 * @class Controlador
 * @brief Clase que gestiona la interacción entre diferentes servicios
 * relacionados con reseñas, cursos y profesores.
 */
class Controlador {
private:
  ResenaServicio resenaServicio; ///< Instancia del servicio de reseñas.
  CursoServicio cursoServicio;   ///< Instancia del servicio de cursos.
  ProfesoresServicio
      profesoresServicio; ///< Instancia del servicio de profesores.

public:
  /**
   * @brief Constructor por defecto de la clase Controlador.
   */
  Controlador() = default;

  /**
   * @brief Destructor de la clase Controlador.
   */
  ~Controlador() = default;

  /**
   * @brief Muestra las reseñas que no han sido revisadas.
   */
  void verResenasNoRevisadas() const;

  /**
   * @brief Actualiza el estado de una reseña específica.
   * @param id_resena Identificador de la reseña a actualizar.
   */
  void actualizarEstadoDeUnaResena(int id_resena);

  /**
   * @brief Muestra los cursos por dificultad y calificación de una escuela.
   * @param escuela Nombre de la escuela.
   */
  void cursosPorCalificacionYDificultad(const std::string &escuela) const;

  /**
   * @brief Elimina una reseña específica.
   * @param id_resena Identificador de la reseña a eliminar.
   */
  void eliminarResena(int id_resena);

  /**
   * @brief Muestra los profesores que imparten un curso específico en una
   * escuela.
   * @param curso Nombre del curso.
   * @param escuela Nombre de la escuela.
   */
  void profesoresPorCursoYEscuela(const std::string &curso,
                                  const std::string &escuela) const;

  /**
   * @brief Muestra todas las reseñas que no han sido revisadas.
   */
  void resenasNoRevisadas() const;

  /**
   * @brief Muestra la lista de todos los profesores.
   */
  void verTodosLosProfesores() const;

  /**
   * @brief Muestra la lista de todos los cursos.
   */
  void verTodosLosCursos() const;

  /**
   * @brief Muestra las reseñas organizadas por calificación y dificultad.
   */
  void resenasPorCalificacionYDificultad() const;

  /**
   * @brief Muestra todas las reseñas.
   */
  void verTodasLasResenas() const;
};

#endif // CONTROLADOR_H_
