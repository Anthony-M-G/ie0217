/**
 * @file conversiones.cpp
 * @brief Definición de funciones para conversiones de unidades de longitud, temperatura y masa.
 */

#include <string>
#include "../includes/conversiones.hpp"

using namespace std;

/**
 * @brief Convierte metros a kilómetros.
 * @param valor Valor en metros.
 * @return Valor en kilómetros.
 */
double metros_a_kilometros(double valor)
{
  return valor / 1000;
}

/**
 * @brief Convierte metros a centímetros.
 * @param valor Valor en metros.
 * @return Valor en centímetros.
 */
double metros_a_centimetros(double valor)
{
  return valor * 100;
}

/**
 * @brief Convierte metros a milímetros.
 * @param valor Valor en metros.
 * @return Valor en milímetros.
 */
double metros_a_milimetros(double valor)
{
  return valor * 1000;
}

/**
 * @brief Convierte kilómetros a metros.
 * @param valor Valor en kilómetros.
 * @return Valor en metros.
 */
double kilometros_a_metros(double valor)
{
  return valor * 1000;
}

/**
 * @brief Convierte centímetros a metros.
 * @param valor Valor en centímetros.
 * @return Valor en metros.
 */
double centimetros_a_metros(double valor)
{
  return valor / 100;
}

/**
 * @brief Convierte milímetros a metros.
 * @param valor Valor en milímetros.
 * @return Valor en metros.
 */
double milimetros_a_metros(double valor)
{
  return valor / 1000;
}

/**
 * @brief Convierte grados Celsius a Fahrenheit.
 * @param valor Valor en grados Celsius.
 * @return Valor en grados Fahrenheit.
 */
double celsius_a_fahrenheit(double valor)
{
  return (valor * 9 / 5) + 32;
}

/**
 * @brief Convierte grados Celsius a Kelvin.
 * @param valor Valor en grados Celsius.
 * @return Valor en grados Kelvin.
 */
double celsius_a_kelvin(double valor)
{
  return valor + 273.15;
}

/**
 * @brief Convierte grados Fahrenheit a Celsius.
 * @param valor Valor en grados Fahrenheit.
 * @return Valor en grados Celsius.
 */
double fahrenheit_a_celsius(double valor)
{
  return (valor - 32) * 5 / 9;
}

/**
 * @brief Convierte grados Fahrenheit a Kelvin.
 * @param valor Valor en grados Fahrenheit.
 * @return Valor en grados Kelvin.
 */
double fahrenheit_a_kelvin(double valor)
{
  return (valor - 32) * 5 / 9 + 273.15;
}

/**
 * @brief Convierte grados Kelvin a Celsius.
 * @param valor Valor en grados Kelvin.
 * @return Valor en grados Celsius.
 */
double kelvin_a_celsius(double valor)
{
  return valor - 273.15;
}

/**
 * @brief Convierte grados Kelvin a Fahrenheit.
 * @param valor Valor en grados Kelvin.
 * @return Valor en grados Fahrenheit.
 */
double kelvin_a_fahrenheit(double valor)
{
  return (valor - 273.15) * 9 / 5 + 32;
}

/**
 * @brief Convierte kilogramos a gramos.
 * @param valor Valor en kilogramos.
 * @return Valor en gramos.
 */
double kilogramos_a_gramos(double valor)
{
  return valor * 1000;
}

/**
 * @brief Convierte kilogramos a miligramos.
 * @param valor Valor en kilogramos.
 * @return Valor en miligramos.
 */
double kilogramos_a_miligramos(double valor)
{
  return valor * 1000000;
}

/**
 * @brief Convierte gramos a kilogramos.
 * @param valor Valor en gramos.
 * @return Valor en kilogramos.
 */
double gramos_a_kilogramos(double valor)
{
  return valor / 1000;
}

/**
 * @brief Convierte gramos a miligramos.
 * @param valor Valor en gramos.
 * @return Valor en miligramos.
 */
double gramos_a_miligramos(double valor)
{
  return valor * 1000;
}

/**
 * @brief Convierte miligramos a kilogramos.
 * @param valor Valor en miligramos.
 * @return Valor en kilogramos.
 */
double miligramos_a_kilogramos(double valor)
{
  return valor / 1000000;
}

/**
 * @brief Convierte miligramos a gramos.
 * @param valor Valor en miligramos.
 * @return Valor en gramos.
 */
double miligramos_a_gramos(double valor)
{
  return valor / 1000;
}
