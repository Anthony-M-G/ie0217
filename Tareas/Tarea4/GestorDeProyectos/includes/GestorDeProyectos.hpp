/**
 * @file GestorDeProyecto.hpp
 * @brief Definición de la clase GestorDeProyectos que administra múltiples
 * proyectos.
 */

#ifndef GESTOR_DE_PROYECTO_H
#define GESTOR_DE_PROYECTO_H

#include "Proyecto.hpp"
#include <map>
#include <string>

/**
 * @class GestorDeProyectos
 * @brief Gestiona múltiples proyectos y sus tareas asociadas.
 *
 * Esta clase permite administrar varios proyectos, cada uno con sus propias
 * tareas, proporcionando funcionalidades para agregar, eliminar y gestionar
 * proyectos y tareas.
 */
class GestorDeProyectos {
public:
  /**
   * @brief Constructor de la clase GestorDeProyectos.
   */
  GestorDeProyectos();

  /**
   * @brief Destructor de la clase GestorDeProyectos.
   */
  ~GestorDeProyectos();

  /**
   * @brief Agrega un nuevo proyecto al gestor.
   * @param proyecto Proyecto a agregar.
   */
  void agregarProyecto(Proyecto &proyecto);

  /**
   * @brief Agrega una tarea a un proyecto específico.
   * @param nombre Nombre del proyecto.
   * @param tarea Puntero a la tarea a agregar.
   */
  void agregarTareaAProyecto(const std::string &nombre, BaseTarea *&tarea);

  /**
   * @brief Elimina una tarea de un proyecto específico.
   * @param nombreProyecto Nombre del proyecto.
   * @param nombreTarea Nombre de la tarea a eliminar.
   */
  void eliminarTareaDeProyecto(const std::string &nombreProyecto,
                               const std::string &nombreTarea);

  /**
   * @brief Elimina un proyecto del gestor.
   * @param nombre Nombre del proyecto a eliminar.
   */
  void eliminarProyecto(const std::string &nombre);

  /**
   * @brief Muestra un resumen de las tareas de un proyecto específico.
   * @param nombre Nombre del proyecto.
   */
  void mostrarResumenTareas(const std::string &nombre) const;

  /**
   * @brief Calcula el costo total de un proyecto.
   * @param nombre Nombre del proyecto.
   */
  void calcularCostoTotal(const std::string &nombre) const;

  /**
   * @brief Calcula el tiempo total estimado de un proyecto.
   * @param nombre Nombre del proyecto.
   */
  void calcularTiempoTotal(const std::string &nombre) const;

  /**
   * @brief Ordena las tareas de un proyecto por costo.
   * @param nombre Nombre del proyecto.
   */
  void ordenarTareasDeProyectoPorCosto(const std::string &nombre) const;

  /**
   * @brief Ordena las tareas de un proyecto por prioridad.
   * @param nombre Nombre del proyecto.
   */
  void ordenarTareasDeProyectoPorPrioridad(const std::string &nombre) const;

  /**
   * @brief Obtiene la lista de todos los proyectos gestionados.
   * @return Mapa de proyectos, donde la clave es el nombre del proyecto.
   */
  std::map<std::string, Proyecto> getListaDeProyectos() const;

private:
  std::map<std::string, Proyecto>
      listaDeProyectos; ///< Mapa que almacena los proyectos, indexados por su
                        ///< nombre
};

#endif // GESTOR_DE_PROYECTO_H