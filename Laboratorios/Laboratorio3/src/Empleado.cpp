#include "../includes/Empleado.hpp"
using namespace std;

Empleado::Empleado(const string &nombre, int id, double salario) : nombre(nombre), id(id), salario(salario) {}

void Empleado::setNombre(const string &nombre)
{
  this->nombre = nombre;
}

string Empleado::getNombre() const
{
  return nombre;
}

void Empleado::setId(int id)
{
  this->id = id;
}

int Empleado::getId() const
{
  return id;
}

void Empleado::setSalario(double s)
{
  salario = s;
}

double Empleado::getSalario() const
{
  return salario;
}

bool compararSalario(const Empleado &e1, const Empleado &e2)
{
  return e1.salario > e2.salario;
}

ostream &operator<<(ostream &os, const Empleado &empleado)
{
  return os << "Nombre: " << empleado.nombre
            << ", ID: " << empleado.id
            << ", Salario: " << empleado.salario << endl;
}
