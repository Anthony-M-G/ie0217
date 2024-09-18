#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP
#include <iostream>
#include <string>
using namespace std;
class Estudiante {
private:
  std::string nombre;
  int edad;

public:
  Estudiante(const std::string &nombre, int edad);
  void mostrarDatos() const;
  ~Estudiante();
};

#endif // ESTUDIANTE_HPP
