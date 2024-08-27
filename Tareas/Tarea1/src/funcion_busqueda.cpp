/**
 * @file funcion_busqueda.cpp
 * @brief Implementación de la función de busqueda de un número en un arreglo.
 */
#include "../includes/funcion_busqueda.hpp"
#include <iostream>
#include "string"

using namespace std;

// Definición de función de busqueda de un número en un arreglo
/**
 * Realiza una búsqueda lineal en un arreglo de enteros para encontrar un número específico.
 *
 * @param primer_elemento Puntero al primer elemento del arreglo.
 * @param cantidad_numeros Cantidad de números en el arreglo.
 * @param numero_a_buscar Número que se desea buscar en el arreglo.
 *
 * @return void
 */
void busqueda(int *primer_elemento, int cantidad_numeros, int numero_a_buscar)
{
  // Itera sobre al arreglo usando el puntero al primer elemento
  bool encontrado = false;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    if (*(primer_elemento + i) == numero_a_buscar)
    {
      cout << "El número " << numero_a_buscar << " se encuentra en la posición " << i << endl;
      encontrado = true; // Cambia el valor de la variable encontrado a true
      break;
    }
  }
  // Si no se encuentra el número en el arreglo, imprime el mensaje
  if (!encontrado)
  {
    cout << "El número " << numero_a_buscar << " no se encuentra en el arreglo" << endl;
  }
};