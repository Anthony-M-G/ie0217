#include <iostream>
using namespace std;

template <typename T> T add(T first_value, T second_value) {
  return (first_value + second_value);
}

int main(int argc, char *argv[]) {
  int result1;
  double result2;

  result1 = add<int>(3, 4); // Hace que el parámetro genérico de tipo T sea ahora int
  cout << result1 << endl;

  result2 = add<double>(3.45, 7.83); // Ahora es de tipo double
  cout << result2 << endl;

  return 0;
}
