/**
 * @file Proyecto.hpp
 * @brief Definición de la clase Proyecto que gestiona un conjunto de tareas.
 */

#ifndef PROYECTO_HPP
#define PROYECTO_HPP

#include "BaseTarea.hpp"
#include <string>
#include <vector>

/**
 * @class Proyecto
 * @brief Representa un proyecto que contiene múltiples tareas.
 *
 * Esta clase permite gestionar un conjunto de tareas de diferentes tipos,
 * utilizando polimorfismo a través de punteros a BaseTarea.
 */
class Proyecto {
private:
  std::string nombreDelProyecto; ///< Nombre del proyecto
  std::vector<BaseTarea *>
      listaDeTareas; ///< Vector de punteros a BaseTarea para almacenar tareas
                     ///< con diferentes tipos de recursos

public:
  /**
   * @brief Constructor de la clase Proyecto.
   * @param nombre Nombre del proyecto (por defecto "Proyecto sin nombre").
   */
  Proyecto(const std::string &nombre = "Proyecto sin nombre");

  /**
   * @brief Destructor de la clase Proyecto.
   *
   * Se encarga de liberar la memoria de las tareas almacenadas.
   */
  ~Proyecto();

  /**
   * @brief Obtiene el nombre del proyecto.
   * @return Nombre del proyecto.
   */
  std::string getNombre() const;

  /**
   * @brief Agrega una nueva tarea al proyecto.
   * @param tarea Puntero a la tarea a agregar.
   */
  void agregarTarea(BaseTarea *&tarea);

  /**
   * @brief Elimina una tarea del proyecto por su nombre.
   * @param nombre Nombre de la tarea a eliminar.
   */
  void eliminarTarea(const std::string &nombre);

  /**
   * @brief Muestra un resumen de todas las tareas del proyecto.
   */
  void mostrarResumen() const;

  /**
   * @brief Ordena las tareas del proyecto por costo.
   */
  void ordenarTareasPorCosto() const;

  /**
   * @brief Ordena las tareas del proyecto por tiempo estimado.
   */
  void ordenarTareasPorTiempoEstimado() const;

  /**
   * @brief Ordena las tareas del proyecto por prioridad.
   */
  void ordenarTareasPorPrioridad() const;

  /**
   * @brief Obtiene la lista de tareas del proyecto.
   * @return Vector de punteros a las tareas del proyecto.
   */
  std::vector<BaseTarea *> getListaDeTareas() const;
};

#endif // PROYECTO_HPP