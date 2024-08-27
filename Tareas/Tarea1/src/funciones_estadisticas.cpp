/**
 * @file funciones_estadisticas.cpp
 * @brief Implementación de las funciones estadísticas.
 */

#include "../includes/funciones_estadisticas.hpp"

#include <iostream>
#include "string"

using namespace std;

/**
 * Calcula la suma de un conjunto de números enteros.
 *
 * Recibe un puntero al primer elemento de un conjunto de números y la cantidad de números en el conjunto.
 * Itera sobre el conjunto, suma los valores y los guarda en la variable suma.
 * @param primer_elemento Puntero al primer elemento del conjunto de números.
 * @param cantidad_numeros Cantidad de números en el conjunto.
 */
void suma(int *primer_elemento, int cantidad_numeros)
{

  // Recorre el arreglo usando el puntero al primer elemento y suma los valores de los elementos guardandolos en la variable total
  int total = 0;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    total += *(primer_elemento + i);
  }
  cout << "La suma de los numeros es: " << total << endl;
};

/**
 * Calcula el promedio de un conjunto de números enteros.
 *
 * Recibe un puntero al primer elemento de un conjunto de números y la cantidad de números en el conjunto.
 * Itera sobre el conjunto y suma los valores de los elementos. Al finalizar, calcula el promedio y lo imprime.
 * @param primer_elemento Puntero al primer elemento del conjunto de números.
 * @param cantidad_numeros Cantidad de números en el conjunto.
 */
void promedio(int *primer_elemento, int cantidad_numeros)
{
  int total = 0;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    total += *(primer_elemento + i);
  }
  double promedio = (double)total / cantidad_numeros;
  cout << "El promedio de los numeros es: " << promedio << endl;
};
/**
 * @brief Encuentra el número máximo en un arreglo de enteros.
 *
 * Esta función recibe un puntero al primer elemento de un arreglo de enteros y la cantidad de números en el arreglo.
 * Itera sobre el arreglo y compara cada elemento con el valor máximo actual. Si encuentra un elemento mayor, actualiza el valor máximi.
 * Al finalizar, imprime el número mínimo encontrado.
 *
 * @param primer_elemento Puntero al primer elemento del arreglo.
 * @param cantidad_numeros Cantidad de números en el arreglo.
 */

void maximo(int *primer_elemento, int cantidad_numeros)
{

  int maximo = *primer_elemento;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    if (*(primer_elemento + i) > maximo)
    {
      maximo = *(primer_elemento + i);
    }
  }
  cout << "El numero maximo es: " << maximo << endl;
};

/**
 * @brief Encuentra el número mínimo en un arreglo de enteros.
 *
 * Esta función recibe un puntero al primer elemento de un arreglo de enteros y la cantidad de números en el arreglo.
 * Itera sobre el arreglo y compara cada elemento con el valor mínimo actual. Si encuentra un elemento menor, actualiza el valor mínimo.
 * Al finalizar, imprime el número mínimo encontrado.
 *
 * @param primer_elemento Puntero al primer elemento del arreglo.
 * @param cantidad_numeros Cantidad de números en el arreglo.
 */
void minimo(int *primer_elemento, int cantidad_numeros)
{

  int minimo = *primer_elemento;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    if (*(primer_elemento + i) < minimo) // Compara el valor del elemento actual con el valor de la variable minimo y si es menor, lo asigna a la variable minimo
    {
      minimo = *(primer_elemento + i);
    }
  }
  cout << "El numero minimo es: " << minimo << endl;
};
