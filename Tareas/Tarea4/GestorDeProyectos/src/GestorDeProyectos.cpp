#include "../includes/GestorDeProyectos.hpp"
#include "../includes/NotFoundException.hpp"
#include <algorithm>
#include <iostream>

GestorDeProyectos::GestorDeProyectos() {}

GestorDeProyectos::~GestorDeProyectos() {}

void GestorDeProyectos::agregarProyecto(Proyecto &proyecto) {
  try {
    listaDeProyectos[proyecto.getNombre()] =
        proyecto; // Se agrega el proyecto al map de proyectos
    std::cout << "Proyecto agregado con éxito" << std::endl;
  } catch (const std::invalid_argument
               &e) { // Se captura la excepción de std::invalid_argument
    std::cerr << e.what() << '\n';
  }
}

void GestorDeProyectos::eliminarTareaDeProyecto(
    const std::string &nombreProyecto, const std::string &nombreTarea) {
  auto proyecto =
      listaDeProyectos.find(nombreProyecto); // Se busca el proyecto en el map

  if (proyecto !=
      listaDeProyectos
          .end()) { // Si el proyecto existe en el map se elimina la tarea
    proyecto->second.eliminarTarea(
        nombreTarea); // Se llama al método eliminarTarea de la clase Proyecto
    std::cout << "Tarea eliminada del proyecto: "
              << proyecto->second.getNombre() << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

// Se agrega la tarea al proyecto
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

// Se elimina el proyecto del map
void GestorDeProyectos::eliminarProyecto(const std::string &nombre) {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    listaDeProyectos.erase(proyecto);
    std::cout << "Proyecto eliminado con éxito" << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

// Se llama al método mostrarResumen de la clase Proyecto
void GestorDeProyectos::mostrarResumenTareas(const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.mostrarResumen();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

// Se calcula el costo total de las tareas del proyecto
void GestorDeProyectos::calcularCostoTotal(const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    double costo_total = 0; // Se inicializa el costo total en 0
    for (auto &tarea : proyecto->second.getListaDeTareas()) {
      costo_total +=
          tarea->getCosto(); // Se suma el costo de cada tarea al costo total
    }
    std::cout << "Proyecto: " << proyecto->second.getNombre()
              << " Costo total: " << costo_total << std::endl;
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

// Se calcula el tiempo total estimado de las tareas del proyecto
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

// Se llama al método ordenarTareasPorCosto de la clase Proyecto
void GestorDeProyectos::ordenarTareasDeProyectoPorCosto(
    const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.ordenarTareasPorCosto();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

// Se llama al método ordenarTareasPorPrioridad de la clase Proyecto
void GestorDeProyectos::ordenarTareasDeProyectoPorPrioridad(
    const std::string &nombre) const {
  auto proyecto = listaDeProyectos.find(nombre);

  if (proyecto != listaDeProyectos.end()) {
    proyecto->second.ordenarTareasPorPrioridad();
    return;
  }
  throw NotFoundException("Proyecto no encontrado");
}

std::map<std::string, Proyecto> GestorDeProyectos::getListaDeProyectos()
    const { // Se retorna el map de proyectos
  return this->listaDeProyectos;
}
