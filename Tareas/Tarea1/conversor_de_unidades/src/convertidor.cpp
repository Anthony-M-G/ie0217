#include "../includes/unidades_de_conversion.hpp"
#include "../includes/conversiones.hpp"
#include "../includes/convertidor.hpp"
#include "../includes/fun_conversion.hpp"
#include <iostream>
#include <string>

using namespace std;

void conversor(UnidadesDeLongitud t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor)); // Crea un puntero a un struct Convertidor que posteriormqente se le asigna memoria

  switch (t_conversion) // switch que evalua el enum UnidadesDeLongitud e identifica la conversion a realizar
  {
  case UnidadesDeLongitud::metros_a_kilometros:
    convertidor->func_conversion = &metros_a_kilometros; // Asigna la funcion metros_a_kilometros al puntero func_conversion y accede a ella mediante el operador flecha
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " km" << endl;
    break;
  case UnidadesDeLongitud::kilometros_a_metros:
    convertidor->func_conversion = &kilometros_a_metros;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " m" << endl;
    break;
  case UnidadesDeLongitud::centimetros_a_metros:
    convertidor->func_conversion = &centimetros_a_metros;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " m" << endl;
    break;
  case UnidadesDeLongitud::milimetros_a_metros:
    convertidor->func_conversion = &milimetros_a_metros;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " m" << endl;
    break;
  case UnidadesDeLongitud::metros_a_centimetros:
    convertidor->func_conversion = &metros_a_centimetros;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " cm" << endl;
    break;
  case UnidadesDeLongitud::metros_a_milimetros:
    convertidor->func_conversion = &metros_a_milimetros;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " mm" << endl;
    break;
  default:
    break;
  }
  free(convertidor);

  return;
}

void conversor(UnidadesDeMasa t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor));

  switch (t_conversion)
  {
  case UnidadesDeMasa::kilogramos_a_gramos:
    convertidor->func_conversion = &kilogramos_a_gramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " g" << endl;
    break;
  case UnidadesDeMasa::gramos_a_kilogramos:
    convertidor->func_conversion = &gramos_a_kilogramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " kg" << endl;
    break;
  case UnidadesDeMasa::miligramos_a_kilogramos:
    convertidor->func_conversion = &miligramos_a_kilogramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " kg" << endl;
    break;
  case UnidadesDeMasa::kilogramos_a_miligramos:
    convertidor->func_conversion = &kilogramos_a_miligramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " mg" << endl;
    break;
  case UnidadesDeMasa::gramos_a_miligramos:
    convertidor->func_conversion = &gramos_a_miligramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " mg" << endl;
    break;
  case UnidadesDeMasa::miligramos_a_gramos:
    convertidor->func_conversion = &miligramos_a_gramos;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " g" << endl;
    break;
  default:
    break;
  }
  free(convertidor);

  return;
}

void conversor(UnidadesDeTemperatura t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor));

  switch (t_conversion)
  {
  case UnidadesDeTemperatura::celsius_a_fahrenheit:
    convertidor->func_conversion = &celsius_a_fahrenheit;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " °F" << endl;
    break;
  case UnidadesDeTemperatura::fahrenheit_a_celsius:
    convertidor->func_conversion = &fahrenheit_a_celsius;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " °C" << endl;
    break;
  case UnidadesDeTemperatura::celsius_a_kelvin:
    convertidor->func_conversion = &celsius_a_kelvin;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " K" << endl;
    break;
  case UnidadesDeTemperatura::kelvin_a_celsius:
    convertidor->func_conversion = &kelvin_a_celsius;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " °C" << endl;
    break;
  case UnidadesDeTemperatura::fahrenheit_a_kelvin:
    convertidor->func_conversion = &fahrenheit_a_kelvin;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " K" << endl;
    break;
  case UnidadesDeTemperatura::kelvin_a_fahrenheit:
    convertidor->func_conversion = &kelvin_a_fahrenheit;
    cout << "El resultado de la conversion es: " << convertidor->func_conversion(t_valor) << " °F" << endl;
    break;
  default:
    break;
  }
  free(convertidor);

  return;
}
