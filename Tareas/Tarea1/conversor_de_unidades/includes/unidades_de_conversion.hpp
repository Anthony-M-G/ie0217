#ifndef UNITS_METRICS_HPP
#define UNITS_METRICS_HPP
// Enums que representan las conversiones de unidades
enum class UnidadesDeLongitud
{
  metros_a_kilometros,
  kilometros_a_metros,
  centimetros_a_metros,
  milimetros_a_metros,
  metros_a_centimetros,
  metros_a_milimetros

};

enum class UnidadesDeMasa
{
  kilogramos_a_gramos,
  gramos_a_kilogramos,
  miligramos_a_kilogramos,
  kilogramos_a_miligramos,
  gramos_a_miligramos,
  miligramos_a_gramos

};

enum class UnidadesDeTemperatura
{
  celsius_a_fahrenheit,
  fahrenheit_a_celsius,
  kelvin_a_celsius,
  celsius_a_kelvin,
  fahrenheit_a_kelvin,
  kelvin_a_fahrenheit

};
#endif