/**
 * @file BaseTarea.hpp
 * @brief Definición de la clase base para tareas genéricas en un proyecto.
 */

#ifndef CLASE_BASE_TAREA_HPP
#define CLASE_BASE_TAREA_HPP

#include "EnumPrioridad.hpp"
#include <iostream>
#include <string>

/**
 * @class BaseTarea
 * @brief Clase base para tareas genéricas con diferentes tipos de recursos en
 * un proyecto.
 *
 * Esta clase define los atributos y métodos básicos necesarios para representar
 * una tarea. Está diseñada para ser heredada por la clase Tarea, permitiendo la
 * creación de tareas con diferentes tipos de recursos.
 */
class BaseTarea {
private:
  std::string nombre;    ///< Nombre de la tarea
  double costo;          ///< Costo de la tarea
  double tiempoEstimado; ///< Tiempo estimado para completar la tarea
  Prioridad prioridad;   ///< Prioridad de la tarea

public:
  /**
   * @brief Constructor de la clase BaseTarea.
   * @param t_nombre Nombre de la tarea.
   * @param costo Costo de la tarea.
   * @param tiempo_estimado Tiempo estimado para completar la tarea.
   * @param prioridad Prioridad de la tarea.
   */
  BaseTarea(const std::string &t_nombre, double costo, double tiempo_estimado,
            Prioridad prioridad);

  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~BaseTarea() = default;

  /**
   * @brief Establece el nombre de la tarea.
   * @param t_nombre Nuevo nombre de la tarea.
   */
  void setNombre(const std::string t_nombre);

  /**
   * @brief Establece el costo de la tarea.
   * @param costo Nuevo costo de la tarea.
   */
  void setCosto(double costo);

  /**
   * @brief Establece el tiempo estimado de la tarea.
   * @param tiempo_estimado Nuevo tiempo estimado de la tarea.
   */
  void setTiempoEstimado(double tiempo_estimado);

  /**
   * @brief Establece la prioridad de la tarea.
   * @param prioridad Nueva prioridad de la tarea.
   */
  void setPrioridad(Prioridad prioridad);

  /**
   * @brief Obtiene el nombre de la tarea.
   * @return Nombre de la tarea.
   */
  std::string getNombre() const;

  /**
   * @brief Obtiene el costo de la tarea.
   * @return Costo de la tarea.
   */
  double getCosto() const;

  /**
   * @brief Obtiene el tiempo estimado de la tarea.
   * @return Tiempo estimado de la tarea.
   */
  double getTiempoEstimado() const;

  /**
   * @brief Obtiene la prioridad de la tarea.
   * @return Prioridad de la tarea.
   */
  Prioridad getPrioridad() const;

  /**
   * @brief Obtiene la prioridad de la tarea como una cadena de texto.
   * @return Prioridad de la tarea como string.
   */
  std::string getPrioridadStr() const;

  /**
   * @brief Método virtual puro para mostrar la información de la tarea.
   *
   * Este método debe ser implementado por las clases derivadas para mostrar
   * la información específica de cada tipo de tarea.
   */
  virtual void mostrarInfo() const = 0;
};

#endif // CLASE_BASE_TAREA_HPP