#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
  string color;
  friend string changeColor(Animal); // Esto es un ejemplo de encapsulamiento en C++ en el cual el atributo color es privado y solo puede ser modificado por la funcion setColor() que es amiga de la clase

protected:
  string type;

public:
  void run() { cout << "I can run -- BASE!" << endl; }
  void eat() { cout << "I can eat!" << endl; }
  void sleep() { cout << "I can sleep!" << endl; }
  void setColor(string clr) { color = clr; }
  string getColor() { return color; }
};

string changeColor(Animal a) // Esta funcion es amiga de la clase Animal y puede acceder a sus atributos privados
{
  a.color = "white";
  return a.color;
}

class Dog : public Animal
{
public:
  void run() { cout << "I can run -- DERIVED!" << endl; } // Este es un ejemplo de polimorfismo en C++ en el cual el metodo run() de la clase base es sobreescrito por el metodo run() de la clase derivada
  void setType(string tp) { type = tp; }
  void displayInfo(string c)
  {
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
  }

  void bark() { cout << "I can bark! Woof woof!!" << endl; }
};

int main()
{
  Dog dog1;
  dog1.run();
  dog1.eat();
  dog1.sleep();
  dog1.setColor("black");
  dog1.bark();
  dog1.setType("Doberman");
  dog1.displayInfo(dog1.getColor());

  cout << "Color after change: " << changeColor(dog1) << endl;

  return 0;
}
