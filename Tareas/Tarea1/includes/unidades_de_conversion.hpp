#ifndef UNITS_METRICS_HPP
#define UNITS_METRICS_HPP

/**
 * @file units_metrics.hpp
 * @brief Define los enums para conversiones de unidades.
 */

/**
 * @enum UnidadesDeLongitud
 * @brief Enum para conversiones entre unidades de longitud.
 */
enum class UnidadesDeLongitud
{
  metros_a_kilometros = 1,  /**< Metros a kilómetros */
  kilometros_a_metros = 2,  /**< Kilómetros a metros */
  centimetros_a_metros = 3, /**< Centímetros a metros */
  milimetros_a_metros = 4,  /**< Milímetros a metros */
  metros_a_centimetros = 5, /**< Metros a centímetros */
  metros_a_milimetros = 6   /**< Metros a milímetros */
};

/**
 * @enum UnidadesDeMasa
 * @brief Enum para conversiones entre unidades de masa.
 */
enum class UnidadesDeMasa
{
  kilogramos_a_gramos = 1,     /**< Kilogramos a gramos */
  gramos_a_kilogramos = 2,     /**< Gramos a kilogramos */
  miligramos_a_kilogramos = 3, /**< Miligramos a kilogramos */
  kilogramos_a_miligramos = 4, /**< Kilogramos a miligramos */
  gramos_a_miligramos = 5,     /**< Gramos a miligramos */
  miligramos_a_gramos = 6      /**< Miligramos a gramos */
};

/**
 * @enum UnidadesDeTemperatura
 * @brief Enum para conversiones entre unidades de temperatura.
 */
enum class UnidadesDeTemperatura
{
  celsius_a_fahrenheit = 1, /**< Celsius a Fahrenheit */
  fahrenheit_a_celsius = 2, /**< Fahrenheit a Celsius */
  kelvin_a_celsius = 3,     /**< Kelvin a Celsius */
  celsius_a_kelvin = 4,     /**< Celsius a Kelvin */
  fahrenheit_a_kelvin = 5,  /**< Fahrenheit a Kelvin */
  kelvin_a_fahrenheit = 6   /**< Kelvin a Fahrenheit */
};

#endif // UNITS_METRICS_HPP
