#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <iostream>
#include <string>

using namespace std;

class Empleado
{
protected:
  int id;
  string nombre;
  double salario;

public:
  Empleado(const string &nombre, int id, double salario); // Firma del constructor de la función

  virtual ~Empleado() = default; // El default indica al compilador que utilice ello

  void setNombre(const string &nombre);
  string getNombre() const; // Los metodos que tienen const al frente quiere decir que la implemnetación de ese método no altera nada del objeto

  void setId(int id);
  int getId() const;

  void setSalario(double s);
  virtual double getSalario() const; // Quiere decir que quien lo herede tien que implementarlo y personalizarlo

  friend bool compararSalario(const Empleado &e1, const Empleado &e2);

  friend ostream &operator<<(ostream &os, const Empleado &empleado); // Sobrecarga el operador <<

  virtual void mostrarInformacion() const = 0; // Al igualarlo a cero lo convierte en un método virtual puro, o sea un metodo que no tiene implementación en la clase base y al tenerlo convierte toda una clase abstracta
};

#endif // EMPLEADO_HPP