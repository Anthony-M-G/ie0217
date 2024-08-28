#include "../includes/EmpleadoMedioTiempo.hpp"

using namespace std;

EmpleadoMedioTiempo::EmpleadoMedioTiempo(const string &nombre, int id, double horasTrabajadas, double tarifaPorHora)
    : Empleado(nombre, id, tarifaPorHora * horasTrabajadas), horasTrabajadas(horasTrabajadas), tarifaPorHora(tarifaPorHora) {}

void EmpleadoMedioTiempo::setHorasTrabajadas(double horasTrabajadas)
{
  this->horasTrabajadas = horasTrabajadas;
}

void EmpleadoMedioTiempo::setTarifaPorHora(double tarifaPorHora)
{
  this->tarifaPorHora = tarifaPorHora;
}

double EmpleadoMedioTiempo::getSalario() const
{
  return horasTrabajadas * tarifaPorHora;
}

void EmpleadoMedioTiempo::mostrarInformacion() const
{
  cout << *this << "Horas trabajadas: " << horasTrabajadas << ", Tarifa por hora: " << tarifaPorHora << endl;
}
