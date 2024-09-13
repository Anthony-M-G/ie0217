#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
   // Usando un vector de enteros
   vector<int> numerosVector = {1, 100, 70, 100};

   set<int> numerosSet = {1, 100, 70, 100}; // Ordena los numeros y no permite repetidos, los de la linea unordered_set no los ordena

   map<int, string> mapNombreValor = {{1, "uno"}, {2, "dos"}, {3, "tres"}};

   cout << "Recorrido de numeros en el vector: " << endl;
   // Vector
   for (auto &num : numerosVector)
   {
      cout << num << ", \t" << endl;
   }
   // Set
   cout << "Recorrido de numeros en el set: " << endl;

   for (auto &num : numerosSet)
   {
      cout << num << ", \t" << endl;
   }

   // Map

   mapNombreValor.insert({4, "Jose"});

   cout << "Recorrido de numeros en el map: " << endl;

   for (auto &par : mapNombreValor)
   {
      cout << par.first << " -> " << par.second << endl;
   }

   return 0;
}
