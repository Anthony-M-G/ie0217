#include <iostream>
#include <vector>
#include "./includes/EmpleadoMedioTiempo.hpp"
#include "./includes/EmpleadoTiempoCompleto.hpp"

using namespace std;

int main()
{
  vector<Empleado *> empleados;
  empleados.push_back(new EmpleadoMedioTiempo("Juan", 1, 20, 120));
  empleados.push_back(new EmpleadoTiempoCompleto("Pedro", 2, 10000, 10, 5));
  empleados.push_back(new EmpleadoMedioTiempo("Maria", 3, 10, 20));
  empleados.push_back(new EmpleadoTiempoCompleto("Ana", 4, 10000, 15, 10));

  for (const auto &empleado : empleados)
  {
    empleado->mostrarInformacion();
  }

  for (const auto &empleado : empleados)
  {
    delete empleado;
  }

  return 0;
}