/**
 * @file convertidor.cpp
 * @brief Implementación de funciones de conversión para unidades de longitud, masa y temperatura usando el puntero a función del struct Convertidor.
 */

#include "../includes/unidades_de_conversion.hpp"
#include "../includes/conversiones.hpp"
#include "../includes/convertidor.hpp"
#include "../includes/fun_conversion.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Realiza la conversión de unidades de longitud.
 *
 * @param t_conversion El tipo de conversión de longitud a realizar (enum UnidadesDeLongitud).
 * @param t_valor El valor en la unidad original que se va a convertir.
 */
void conversor(UnidadesDeLongitud t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor)); // Reserva memoria para un struct Convertidor

  switch (t_conversion)
  {
  case UnidadesDeLongitud::metros_a_kilometros:
    convertidor->func_conversion = &metros_a_kilometros;
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
  free(convertidor); // Libera la memoria asignada al struct Convertidor

  return;
}

/**
 * @brief Realiza la conversión de unidades de masa.
 *
 * @param t_conversion El tipo de conversión de masa a realizar (enum UnidadesDeMasa).
 * @param t_valor El valor en la unidad original que se va a convertir.
 */
void conversor(UnidadesDeMasa t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor)); // Reserva memoria para un struct Convertidor

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
  free(convertidor); // Libera la memoria asignada al struct Convertidor

  return;
}

/**
 * @brief Realiza la conversión de unidades de temperatura.
 *
 * @param t_conversion El tipo de conversión de temperatura a realizar (enum UnidadesDeTemperatura).
 * @param t_valor El valor en la unidad original que se va a convertir.
 */
void conversor(UnidadesDeTemperatura t_conversion, double t_valor)
{
  Convertidor *convertidor = (Convertidor *)malloc(sizeof(Convertidor)); // Reserva memoria para un struct Convertidor

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
  free(convertidor); // Libera la memoria asignada al struct Convertidor

  return;
}
