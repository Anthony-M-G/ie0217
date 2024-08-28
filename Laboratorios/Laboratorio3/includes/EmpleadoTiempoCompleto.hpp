#ifndef EMPLEADO_TIEMPO_COMPLETO
#define EMPLEADO_TIEMPO_COMPLETO
#include "./Empleado.hpp"

class EmpleadoTiempoCompleto : public Empleado
{
private:
  double bonificacion;
  double deduccion;

public:
  EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion);

  void setBonificacion(double bonificacion);

  void setDeduccion(double deduccion);

  double getSalario() const override;

  void mostrarInformacion() const override;
};

#endif
