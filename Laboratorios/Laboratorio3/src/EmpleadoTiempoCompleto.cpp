#include "../includes/EmpleadoTiempoCompleto.hpp"

using namespace std;

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion) : Empleado(nombre, id, salario), bonificacion(bonificacion), deduccion(deduccion) {}

void EmpleadoTiempoCompleto::setBonificacion(double bonificacion)
{
  this->bonificacion = bonificacion;
}

void EmpleadoTiempoCompleto::setDeduccion(double deduccion)
{
  this->deduccion = deduccion;
}

double EmpleadoTiempoCompleto::getSalario() const
{
  return salario + bonificacion - deduccion;
}

void EmpleadoTiempoCompleto::mostrarInformacion() const
{
  cout << *this << "Bonificación: " << bonificacion << ", Deducción: " << deduccion << endl;
}