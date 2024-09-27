#include "../includes/Proyecto.hpp"
#include "../includes/NotFoundException.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

Proyecto::Proyecto(const std::string &nombre) : nombreDelProyecto(nombre) {}

std::string Proyecto::getNombre() const { return this->nombreDelProyecto; }

Proyecto::~Proyecto() {
  for (auto &tarea : listaDeTareas) {
    delete tarea;
  }
}

void Proyecto::agregarTarea(BaseTarea *&tarea) {
  try {
    listaDeTareas.push_back(tarea);
    std::cout << "Tarea agregada con éxito" << std::endl;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
  }
}

void Proyecto::eliminarTarea(const std::string &nombre) {
  auto element = std::find_if(listaDeTareas.begin(), listaDeTareas.end(),
                              [&nombre](const BaseTarea *tarea) {
                                return tarea->getNombre() == nombre;
                              });
  if (element != listaDeTareas.end()) {
    listaDeTareas.erase(element);
    std::cout << "Tarea eliminada con éxito" << std::endl;
  } else {
    throw NotFoundException(
        "Tarea no encontrada"); // Se lanza una excepción propia
  }
}

void Proyecto::mostrarResumen() const {
  std::cout << "Nombre del proyecto: " << this->nombreDelProyecto << std::endl;
  std::cout << "Número de tareas: " << this->listaDeTareas.size() << std::endl;
  double costo_total = 0;
  for (const auto &tarea : listaDeTareas) {
    costo_total += tarea->getCosto();
  }
  std::cout << "Costo total: " << costo_total << std::endl;
  double tiempo_total = 0;
  for (const auto &tarea : listaDeTareas) {
    tiempo_total += tarea->getTiempoEstimado();
  }
  std::cout << "Tiempo total estimado: " << tiempo_total << " meses"
            << std::endl;
}

void Proyecto::ordenarTareasPorCosto() const {
  std::vector<BaseTarea *> listaPorCosto(
      this->listaDeTareas
          .size()); // Se crea un vector de punteros a BaseTarea para almacenar
                    // las tareas ordenadas por costo
  std::copy(
      this->listaDeTareas.begin(),
      this->listaDeTareas.end(), // Se copian las tareas del proyecto al nuevo
                                 // verctor para no alterar el original
      listaPorCosto.begin());

  std::sort( // Se ordenan las tareas por costo de mayor a menor
      listaPorCosto.begin(), listaPorCosto.end(),
      [](BaseTarea *a, BaseTarea *b) { return a->getCosto() > b->getCosto(); });

  std::cout << "------------------------------------Tareas ordenadas por "
               "costo-------------------------------------"
            << std::endl;
  for (auto &item : listaPorCosto) {
    item->mostrarInfo();
  }

  std::cout << "Fin de la ordenación" << std::endl;

  listaPorCosto.clear(); // Libera la memoria asignada al vector

  return;
}

void Proyecto::ordenarTareasPorTiempoEstimado() const {
  std::vector<BaseTarea *> listaPorTiempoEstimado(
      this->listaDeTareas
          .size()); // Se crea un vector de punteros a BaseTarea para almacenar
                    // las tareas ordenadas por tiempo estimado
  std::copy(
      this->listaDeTareas.begin(),
      this->listaDeTareas.end(), // Se copian las tareas del proyecto al nuevo
                                 // verctor para no alterar el original
      listaPorTiempoEstimado.begin());

  std::sort( // Se ordenan las tareas por tiempo estimado de mayor a menor
      listaPorTiempoEstimado.begin(), listaPorTiempoEstimado.end(),
      [](BaseTarea *a, BaseTarea *b) {
        return a->getTiempoEstimado() > b->getTiempoEstimado();
      });

  std::cout << "------------------------------------Tareas ordenadas por "
               "tiempo estimado-------------------------------------"
            << std::endl;
  for (auto &item : listaPorTiempoEstimado) {
    item->mostrarInfo();
  }

  std::cout << "Fin de la ordenación" << std::endl;

  listaPorTiempoEstimado.clear(); // Libera la memoria asignada al vector

  return;
}

void Proyecto::ordenarTareasPorPrioridad() const {
  std::vector<BaseTarea *> listaPorPrioridad(
      this->listaDeTareas
          .size()); // Se crea un vector de punteros a BaseTarea para almacenar
                    // las tareas ordenadas por prioridad
  std::copy(
      this->listaDeTareas.begin(),
      this->listaDeTareas.end(), // Se copian las tareas del proyecto al nuevo
                                 // verctor para no alterar el original
      listaPorPrioridad.begin());

  std::sort( // Se ordenan las tareas por prioridad de mayor a menor
      listaPorPrioridad.begin(), listaPorPrioridad.end(),
      [](BaseTarea *a, BaseTarea *b) {
        return a->getPrioridad() <
               b->getPrioridad(); // Se ordena de menor a mayor prioridad ya que
                                  // la mayor prioridad es el menor número
      });

  std::cout << "------------------------------------Tareas ordenadas por "
               "prioridad-------------------------------------"
            << std::endl;
  for (auto &item : listaPorPrioridad) {
    item->mostrarInfo();
  }

  std::cout << "Fin de la ordenación" << std::endl;

  listaPorPrioridad.clear(); // Libera la memoria asignada al vector

  return;
}

std::vector<BaseTarea *> Proyecto::getListaDeTareas() const {
  return this->listaDeTareas;
}