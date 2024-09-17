#include <iostream>
#include <ostream>
template <typename T> class Number {
private:
  T num;

public:
  Number(T num) : num(num) {} // Constructor
  T getNum() { return this->num; }
};

int main(int argc, char *argv[]) {
  Number<int> numberInt(10); // Hace que el tipo del atributo num sea int
  std::cout << "Numero entero: " << numberInt.getNum() << std::endl;
  Number<double> numDouble(8.99);
  std::cout << "Numero double: " << numDouble.getNum() << std::endl;
  return 0;
}
