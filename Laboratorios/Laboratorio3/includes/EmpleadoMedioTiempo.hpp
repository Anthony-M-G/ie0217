#ifndef EMPLEADO_MEDIO_TIEMPO
#define EMPLEADO_MEDIO_TIEMPO

#include "./Empleado.hpp"

class EmpleadoMedioTiempo : public Empleado
{
private:
  double horasTrabajadas;
  double tarifaPorHora;

public:
  EmpleadoMedioTiempo(const string &nombre, int id, double horasTrabajadas, double tarifaPorHora);

  void setHorasTrabajadas(double horasTrabajadas);

  void setTarifaPorHora(double tarifaPorHora);

  double getSalario() const override;

  void mostrarInformacion() const override;
};

#endif // EMPLEADO_MEDIO_TIEMPO