/**
 * @file Profesor.h
 * @brief Clase que representa un profesor en el sistema educativo.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include <iostream>

/**
 * @class Profesor
 * @brief Clase que gestiona la información de un profesor.
 *
 * Esta clase mantiene la información básica de un profesor,
 * incluyendo su identificador único, nombre y la escuela
 * a la que pertenece.
 */
class Profesor {
private:
  int id_profesor;     /**< Identificador único del profesor */
  std::string nombre;  /**< Nombre completo del profesor */
  std::string escuela; /**< Nombre de la escuela donde trabaja el profesor */

public:
  /**
   * @brief Constructor por defecto
   */
  Profesor();

  /**
   * @brief Constructor parametrizado
   * @param id_profesor Identificador único del profesor
   * @param nombre Nombre completo del profesor
   * @param escuela Nombre de la escuela donde trabaja
   */
  Profesor(int id_profesor, const std::string &nombre,
           const std::string &escuela);

  /**
   * @brief Destructor de la clase
   */
  ~Profesor();

  /**
   * @brief Obtiene el ID del profesor
   * @return Identificador único del profesor
   */
  int getIdProfesor() const;

  /**
   * @brief Establece el ID del profesor
   * @param id_profesor Nuevo identificador del profesor
   */
  void setIdProfesor(int id_profesor);

  /**
   * @brief Obtiene el nombre del profesor
   * @return Nombre completo del profesor
   */
  std::string getNombre() const;

  /**
   * @brief Establece el nombre del profesor
   * @param nombre Nuevo nombre del profesor
   */
  void setNombre(const std::string &nombre);

  /**
   * @brief Obtiene el nombre de la escuela
   * @return Nombre de la escuela donde trabaja el profesor
   */
  std::string getEscuela() const;

  /**
   * @brief Establece el nombre de la escuela
   * @param escuela Nueva escuela del profesor
   */
  void setEscuela(const std::string &escuela);

  /**
   * @brief Sobrecarga del operador de inserción para imprimir los datos del
   * profesor
   * @param os Stream de salida
   * @param profesor Objeto Profesor a imprimir
   * @return Referencia al stream de salida
   */
  friend std::ostream &operator<<(std::ostream &os, const Profesor &profesor);
};

#endif // PROFESOR_H_