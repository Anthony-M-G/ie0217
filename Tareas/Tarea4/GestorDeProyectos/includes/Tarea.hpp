/**
 * @file Tarea.hpp
 * @brief Definición de la clase template Tarea que hereda de BaseTarea.
 */

#ifndef TAREA_HPP
#define TAREA_HPP

#include "BaseTarea.hpp"
#include "EnumPrioridad.hpp"
#include <iostream>
#include <string>

/**
 * @class Tarea
 * @brief Clase template que representa una tarea específica con un tipo de
 * recurso.
 *
 * Esta clase hereda de BaseTarea y añade funcionalidad específica para manejar
 * un recurso de tipo genérico.
 *
 * @tparam Recurso Tipo del recurso asociado a la tarea.
 */
template <typename Recurso> class Tarea : public BaseTarea {
public:
  /**
   * @brief Constructor de la clase Tarea.
   * @param t_nombre Nombre de la tarea.
   * @param costo Costo de la tarea.
   * @param tiempo_estimado Tiempo estimado para completar la tarea.
   * @param prioridad Prioridad de la tarea.
   * @param t_recurso Recurso asociado a la tarea.
   */
  Tarea(const std::string &t_nombre, double costo, double tiempo_estimado,
        Prioridad prioridad, Recurso t_recurso);

  /**
   * @brief Establece el recurso de la tarea.
   * @param t_recurso Nuevo recurso para la tarea.
   */
  void setRecurso(Recurso t_recurso);

  /**
   * @brief Obtiene el recurso de la tarea.
   * @return Recurso asociado a la tarea.
   */
  Recurso getRecurso() const;

  /**
   * @brief Muestra la información detallada de la tarea.
   *
   * Este método implementa la función virtual pura de la clase base,
   * mostrando toda la información de la tarea, incluido el recurso específico.
   */
  void mostrarInfo() const override;

private:
  Recurso recurso; ///< Recurso específico asociado a la tarea
};

// Implementación de los métodos de la clase template

template <typename Recurso>
Tarea<Recurso>::Tarea(const std::string &t_nombre, double costo,
                      double tiempo_estimado, Prioridad prioridad,
                      Recurso t_recurso)
    : BaseTarea(t_nombre, costo, tiempo_estimado, prioridad),
      recurso(t_recurso) {}

template <typename Recurso> void Tarea<Recurso>::setRecurso(Recurso t_recurso) {
  this->recurso = t_recurso;
}

template <typename Recurso> Recurso Tarea<Recurso>::getRecurso() const {
  return this->recurso;
}

template <typename Recurso> void Tarea<Recurso>::mostrarInfo() const {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Nombre: " << this->getNombre() << std::endl;
  std::cout << "Costo: " << this->getCosto() << std::endl;
  std::cout << "Tiempo estimado: " << this->getTiempoEstimado() << " semanas"
            << std::endl;
  std::cout << "Prioridad: " << this->getPrioridadStr() << std::endl;
  std::cout << "Recurso: " << this->recurso << std::endl;
  std::cout << "------------------------------------" << std::endl;
}

#endif // TAREA_HPP