/**
 * @file Curso.h
 * @brief Clase que representa un curso en el sistema educativo.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef CURSO_H_
#define CURSO_H_

#include "Resena.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class Curso
 * @brief Clase que gestiona la información de un curso académico.
 *
 * Esta clase mantiene información sobre un curso específico, incluyendo
 * su identificador único, nombre, profesor asignado y las reseñas
 * asociadas al mismo.
 */
class Curso {
private:
  int id_curso;             /**< Identificador único del curso */
  std::string nombre_curso; /**< Nombre del curso */
  int id_profesor;          /**< Identificador del profesor asignado */

  /**
   * @brief Sobrecarga del operador de inserción para imprimir el curso
   * @param os Stream de salida
   * @param curso Objeto Curso a imprimir
   * @return Referencia al stream de salida
   */
  friend std::ostream &operator<<(std::ostream &os, const Curso &curso);

public:
  /**
   * @brief Constructor por defecto
   */
  Curso();

  /**
   * @brief Constructor parametrizado
   * @param id_curso Identificador del curso
   * @param nombre_curso Nombre del curso
   * @param id_profesor Identificador del profesor
   */
  Curso(int id_curso, const std::string &nombre_curso, int id_profesor);

  /**
   * @brief Destructor de la clase
   */
  ~Curso();

  /**
   * @brief Obtiene el ID del curso
   * @return Identificador del curso
   */
  int getIdCurso() const;

  /**
   * @brief Establece el ID del curso
   * @param id_curso Nuevo identificador del curso
   */
  void setIdCurso(int id_curso);

  /**
   * @brief Obtiene el nombre del curso
   * @return Nombre del curso
   */
  std::string getNombreCurso() const;

  /**
   * @brief Establece el nombre del curso
   * @param nombre_curso Nuevo nombre del curso
   */
  void setNombreCurso(const std::string &nombre_curso);

  /**
   * @brief Obtiene el ID del profesor
   * @return Identificador del profesor
   */
  int getIdProfesor() const;

  /**
   * @brief Establece el ID del profesor
   * @param id_profesor Nuevo identificador del profesor
   */
  void setIdProfesor(int id_profesor);

  /**
   * @brief Obtiene el vector de reseñas del curso
   * @return Vector con las reseñas asociadas al curso
   */
};

#endif // CURSO_H_