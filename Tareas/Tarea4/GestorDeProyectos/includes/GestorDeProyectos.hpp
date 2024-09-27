#ifndef GESTOR_DE_PROYECTO_H
#define GESTOR_DE_PROYECTO_H

#include "Proyecto.hpp"
#include <map>
#include <string>

class GestorDeProyectos {
public:
  GestorDeProyectos();
  ~GestorDeProyectos();
  void agregarProyecto(Proyecto &proyecto);
  void agregarTareaAProyecto(const std::string &nombre, BaseTarea *&tarea);
  void eliminarTareaDeProyecto(const std::string &nombreProyecto,
                               const std::string &nombreTarea);
  void eliminarProyecto(const std::string &nombre);
  void mostrarResumenTareas(const std::string &nombre) const;
  void calcularCostoTotal(const std::string &nombre) const;
  void calcularTiempoTotal(const std::string &nombre) const;
  void ordenarTareasDeProyectoPorCosto(const std::string &nombre) const;
  void ordenarTareasDeProyectoPorPrioridad(const std::string &nombre) const;
  std::map<std::string, Proyecto> getListaDeProyectos() const;

private:
  std::map<std::string, Proyecto> listaDeProyectos;
};

#endif // GESTOR_DE_PROYECTO_H