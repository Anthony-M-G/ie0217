#include <iostream>

using namespace std;
// pasando argumentos por consola
int main(int argc, char *argv[])
{
  try // probando el try-catch que no estaba en c
  {
    if (argc == 2)
    {
      cout << "Número de argumentos: " << argc << endl;
      int a = atoi(argv[1]); // función atoi convierte un string a un entero
      cout << "Argumento 1 atoi: " << a << endl;
      for (int i = 0; i < argc; i++)
      {
        cout << "Argumento " << i << ": " << argv[i] << endl;
      }
    }
    else
      throw std::invalid_argument("No se han pasado argumentos"); // lanzo una excepción si no se pasan argumentos
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}