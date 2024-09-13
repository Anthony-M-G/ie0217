#include <iostream>
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  vector<string> languages = {"Python", "C++", "Java", "Javascript"};

  // Creando el iterador
  vector<string>::iterator itr; // esto es un forward iterator

  for (itr = languages.begin(); itr != languages.end(); itr++)
  {
    std::cout << *itr << ", \t";
  }

  return 0;
}
