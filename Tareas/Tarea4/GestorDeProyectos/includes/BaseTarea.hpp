#ifndef CLASE_BASE_TAREA_HPP
#define CLASE_BASE_TAREA_HPP

#include "EnumPrioridad.hpp"
#include <iostream>
#include <string>

class BaseTarea { // Se define la clase BaseTarea con los atributos y métodos
                  // necesarios para poder ser heredada por la clase Tarea y así
                  // poder tener tareas genéricas con diferentes tipos de
                  // recursos en un proyecto
private:
  std::string nombre;
  double costo;
  double tiempoEstimado;
  Prioridad prioridad;

public:
  BaseTarea(const std::string &t_nombre, double costo, double tiempo_estimado,
            Prioridad prioridad);
  virtual ~BaseTarea() = default;

  void setNombre(const std::string t_nombre);
  void setCosto(double costo);
  void setTiempoEstimado(double tiempo_estimado);
  void setPrioridad(Prioridad prioridad);

  std::string getNombre() const;
  double getCosto() const;
  double getTiempoEstimado() const;
  Prioridad getPrioridad() const;

  std::string getPrioridadStr() const;

  virtual void mostrarInfo() const = 0;
};

#endif