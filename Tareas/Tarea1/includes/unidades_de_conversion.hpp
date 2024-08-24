#ifndef UNITS_METRICS_HPP
#define UNITS_METRICS_HPP
// Enums que representan las conversiones de unidades
enum class UnidadesDeLongitud
{
  metros_a_kilometros = 1,
  kilometros_a_metros = 2,
  centimetros_a_metros = 3,
  milimetros_a_metros = 4,
  metros_a_centimetros = 5,
  metros_a_milimetros = 6

};

enum class UnidadesDeMasa
{
  kilogramos_a_gramos = 1,
  gramos_a_kilogramos = 2,
  miligramos_a_kilogramos = 3,
  kilogramos_a_miligramos = 4,
  gramos_a_miligramos = 5,
  miligramos_a_gramos = 6

};

enum class UnidadesDeTemperatura
{
  celsius_a_fahrenheit = 1,
  fahrenheit_a_celsius = 2,
  kelvin_a_celsius = 3,
  celsius_a_kelvin = 4,
  fahrenheit_a_kelvin = 5,
  kelvin_a_fahrenheit = 6

};
#endif