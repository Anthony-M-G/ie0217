#include "../includes/GestorDeProyectos.hpp"
#include "../includes/NotFoundException.hpp"
#include <algorithm>
#include <iostream>

GestorDeProyectos::GestorDeProyectos() {}

GestorDeProyectos::~GestorDeProyectos() {}

void GestorDeProyectos::agregarProyecto(Proyecto &proyecto) {
  try {
    listaDeProyectos[proyecto.getNombre()] = proyecto;
    std::cout << "Proyecto agregado con éxito" << std::endl;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
  }
}

void GestorDeProyectos::eliminarTareaDeProyecto(
    const std::string &nombreProyecto, const std::string &nombreTarea) {
  auto proyecto = listaDeProyectos.find(nombreProyecto);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.eliminarTarea(nombreTarea);
    std::cout << "Tarea eliminada del proyecto: "
              << proyecto->second.getNombre() << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::agregarTareaAProyecto(const std::string &nombre,
                                              BaseTarea *&tarea) {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.agregarTarea(tarea);
    std::cout << "Tarea agregada al proyecto: " << proyecto->second.getNombre()
              << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::eliminarProyecto(const std::string &nombre) {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    listaDeProyectos.erase(proyecto);
    std::cout << "Proyecto eliminado con éxito" << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::mostrarResumenTareas(const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.mostrarResumen();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::calcularCostoTotal(const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    double costo_total = 0;
    for (auto &tarea : proyecto->second.getListaDeTareas()) {
      costo_total += tarea->getCosto();
    }
    std::cout << "Proyecto: " << proyecto->second.getNombre()
              << " Costo total: " << costo_total << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::calcularTiempoTotal(const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    double tiempo_total = 0;
    for (auto &tarea : proyecto->second.getListaDeTareas()) {
      tiempo_total += tarea->getTiempoEstimado();
    }
    std::cout << "Proyecto: " << proyecto->second.getNombre()
              << " Tiempo total: " << tiempo_total << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::ordenarTareasDeProyectoPorCosto(
    const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.ordenarTareasPorCosto();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

void GestorDeProyectos::ordenarTareasDeProyectoPorPrioridad(
    const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.ordenarTareasPorPrioridad();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

std::map<std::string, Proyecto> GestorDeProyectos::getListaDeProyectos() const {
  return this->listaDeProyectos;
}
