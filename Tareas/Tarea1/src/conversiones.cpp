#include <string>

#include "../includes/conversiones.hpp"

using namespace std;
// Conversiones de unidades de longitud
double metros_a_kilometros(double valor)
{
  return valor / 1000;
};

double metros_a_centimetros(double valor)
{
  return valor * 100;
};

double metros_a_milimetros(double valor)
{
  return valor * 1000;
};

double kilometros_a_metros(double valor)
{
  return valor * 1000;
};

double centimetros_a_metros(double valor)
{
  return valor / 100;
};

double milimetros_a_metros(double valor)
{
  return valor / 1000;
};

// Conversiones de unidades de temperatura
double celsius_a_fahrenheit(double valor)
{
  return (valor * 9 / 5) + 32;
};

double celsius_a_kelvin(double valor)
{
  return valor + 273.15;
};

double fahrenheit_a_celsius(double valor)
{
  return (valor - 32) * 5 / 9;
};

double fahrenheit_a_kelvin(double valor)
{
  return (valor - 32) * 5 / 9 + 273.15;
};

double kelvin_a_celsius(double valor)
{
  return valor - 273.15;
};

double kelvin_a_fahrenheit(double valor)
{
  return (valor - 273.15) * 9 / 5 + 32;
};

// Conversiones de unidades de masa
double kilogramos_a_gramos(double valor)
{
  return valor * 1000;
};

double kilogramos_a_miligramos(double valor)
{
  return valor * 1000000;
};

double gramos_a_kilogramos(double valor)
{
  return valor / 1000;
};

double gramos_a_miligramos(double valor)
{
  return valor * 1000;
};

double miligramos_a_kilogramos(double valor)
{
  return valor / 1000000;
};

double miligramos_a_gramos(double valor)
{
  return valor / 1000;
};
