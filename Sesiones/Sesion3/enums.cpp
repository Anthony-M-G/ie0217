#include <iostream>

using namespace std;

#define MI_PRIMER_DEFINE 925

enum seasons
{
  spring = 34,
  summer = 4,
  autumn = 9,
  winter = 32
};

enum enumcito
{
  carro,
  casa,
  arbol,
  patio
};

int main()
{

  seasons s;
  s = summer;
  cout << "summer: " << s << endl;

  cout << "Define: " << MI_PRIMER_DEFINE << endl;

  cout << "carro: " << carro << endl; // si no le indico un valor, el enum empieza en 0 y se incrementa en 1 como en un arreglo
  return 0;
}