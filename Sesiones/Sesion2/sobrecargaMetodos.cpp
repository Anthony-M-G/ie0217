#include <iostream>

/**
 * Sobre carga de métodos en C++
 * Los métodos sobrecargados son lso que tienen mismo nombre
 * pero diferente número de parámetros o diferente tipo de parámetros
 */
int suma(int a, int b);
float suma(float a, float b);
int suma(int a, int b, int c);
int main()
{
  int sumaint = suma(5, 5);
  int sumaint3 = suma(5, 5, 5);
  float sumafloat = suma((float)5.5, (float)5.5);
  std::cout << "Suma int: " << sumaint << std::endl;
  std::cout << "Suma int 3: " << sumaint3 << std::endl;
  std::cout << "Suma float: " << sumafloat << std::endl;
  return 0;
}

int suma(int a, int b)
{
  return a + b;
}

float suma(float a, float b)
{
  return a + b;
}

int suma(int a, int b, int c)
{
  return a + b + c;
}