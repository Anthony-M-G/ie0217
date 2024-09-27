#ifndef TAREA_HPP
#define TAREA_HPP
#include "BaseTarea.hpp"
#include "EnumPrioridad.hpp"
#include <iostream>
#include <string>
template <typename Recurso>
class Tarea : public BaseTarea { // Clase que hereda de BaseTarea
public:
  Tarea(const std::string &t_nombre, double costo, double tiempo_estimado,
        Prioridad prioridad, Recurso t_recurso)
      : BaseTarea(t_nombre, costo, tiempo_estimado, prioridad),
        recurso(t_recurso){};

  void setRecurso(Recurso t_recurso) { this->recurso = t_recurso; };
  Recurso getRecurso() const { return this->recurso; };

  void mostrarInfo() const {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Nombre: " << this->getNombre() << std::endl;
    std::cout << "Costo: " << this->getCosto() << std::endl;
    std::cout << "Tiempo estimado: " << this->getTiempoEstimado() << " semanas"
              << std::endl;
    std::cout << "Prioridad: " << this->getPrioridadStr() << std::endl;
    std::cout << "Recurso: " << this->recurso << std::endl;
    std::cout << "------------------------------------" << std::endl;
  };

private:
  Recurso recurso;
};
#endif