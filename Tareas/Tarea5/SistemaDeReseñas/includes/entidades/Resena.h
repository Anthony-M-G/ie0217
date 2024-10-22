/**
 * @file Resena.h
 * @brief Clase que representa una reseña de un curso y profesor.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef RESENHAS_H_
#define RESENHAS_H_

#include <iostream>
#include <string>

/**
 * @class Resena
 * @brief Clase que gestiona las reseñas de cursos y profesores.
 *
 * Esta clase maneja las reseñas que los estudiantes pueden hacer sobre
 * los cursos y profesores, incluyendo calificaciones, comentarios y
 * niveles de dificultad.
 */
class Resena {
private:
  int id_resena;            /**< Identificador único de la reseña */
  std::string comentario;   /**< Comentario textual de la reseña */
  int calificacion;         /**< Calificación numérica básica */
  int id_profesor;          /**< ID del profesor evaluado */
  int id_curso;             /**< ID del curso evaluado */
  int calificacion_general; /**< Calificación general del curso/profesor */
  int nivel_dificultad;     /**< Nivel de dificultad percibido */
  bool revisado;            /**< Indica si la reseña ha sido revisada */

public:
  /**
   * @brief Constructor por defecto
   */
  Resena();

  /**
   * @brief Constructor parametrizado
   * @param id_profesor ID del profesor evaluado
   * @param id_curso ID del curso evaluado
   * @param calificacion Calificación numérica
   * @param nivel_dificultad Nivel de dificultad del curso
   * @param comentario Comentario textual de la reseña
   */
  Resena(int id_profesor, int id_curso, int calificacion, int nivel_dificultad,
         const std::string &comentario);

  /**
   * @brief Destructor de la clase
   */
  ~Resena();

  /**
   * @brief Obtiene el ID de la reseña
   * @return Identificador único de la reseña
   */
  int getIdResena() const;

  /**
   * @brief Establece el ID de la reseña
   * @param id_resena Nuevo identificador de la reseña
   */
  void setIdResena(int id_resena);

  /**
   * @brief Obtiene el comentario de la reseña
   * @return Comentario textual
   */
  std::string getComentario();

  /**
   * @brief Establece el comentario de la reseña
   * @param comentario Nuevo comentario
   */
  void setComentario(const std::string &comentario);

  /**
   * @brief Obtiene la calificación
   * @return Calificación numérica
   */
  int getCalificacion() const;

  /**
   * @brief Establece la calificación
   * @param calificacion Nueva calificación
   */
  void setCalificacion(int calificacion);

  /**
   * @brief Obtiene el ID del profesor
   * @return ID del profesor evaluado
   */
  int getIdProfesor() const;

  /**
   * @brief Establece el ID del profesor
   * @param id_profesor Nuevo ID del profesor
   */
  void setIdProfesor(int id_profesor);

  /**
   * @brief Obtiene el ID del curso
   * @return ID del curso evaluado
   */
  int getIdCurso() const;

  /**
   * @brief Establece el ID del curso
   * @param id_curso Nuevo ID del curso
   */
  void setIdCurso(int id_curso);

  /**
   * @brief Obtiene la calificación general
   * @return Calificación general del curso/profesor
   */
  int getCalificacionGeneral() const;

  /**
   * @brief Establece la calificación general
   * @param calificacion_general Nueva calificación general
   */
  void setCalificacionGeneral(int calificacion_general);

  /**
   * @brief Obtiene el nivel de dificultad
   * @return Nivel de dificultad del curso
   */
  int getNivelDificultad() const;

  /**
   * @brief Establece el nivel de dificultad
   * @param nivel_dificultad Nuevo nivel de dificultad
   */
  void setNivelDificultad(int nivel_dificultad);

  /**
   * @brief Obtiene el estado de revisión
   * @return true si la reseña ha sido revisada, false en caso contrario
   */
  bool getRevisado() const;

  /**
   * @brief Establece el estado de revisión
   * @param revisado Nuevo estado de revisión
   */
  void setRevisado(bool revisado);

  /**
   * @brief Sobrecarga del operador de inserción para imprimir la reseña
   * @param os Stream de salida
   * @param resena Objeto Resena a imprimir
   * @return Referencia al stream de salida
   */
  friend std::ostream &operator<<(std::ostream &os, const Resena &resena);
};

#endif // RESENHAS_H_