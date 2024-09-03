#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int num;
  cout << "Ingrese la cantidad de estudiantes: ";
  cin >> num;

  // Crear un arreglo de tamaño num en el heap
  double *arr = new double[num];

  for (int i = 0; i < num; i++)
  {
    cout << "Dirección de memoria de la nota del estudiante " << i + 1 << ": " << (arr + i) << endl;
    cout << "Ingrese la nota del estudiante (Valor que se guarda en la direccion en memoria actual) " << i + 1 << ": ";
    cin >> *(arr + i); // cada nota se almacenará en la dirección de memoria arr + i, ya que arr apunta a la primera dirección de memoria del arreglo
  }

  cout << "Notas de los estudiantes: " << endl;
  for (int i = 0; i < num; i++)
  {
    cout << "Estudiante " << i + 1 << ": " << *(arr + i) << endl;
  }

  delete[] arr;
  return 0;
}
