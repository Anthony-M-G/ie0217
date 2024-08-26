#include "../includes/funciones_estadisticas.hpp"

#include <iostream>
#include "string"

using namespace std;

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
