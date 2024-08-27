#include <iostream>
using namespace std;

class Student
{
public:
  double marks;

  Student(double m)
  {
    marks = m;
  }
};

void calculateAverage(Student s1, Student s2) // Pasando objetos como argumentos
{
  double average = (s1.marks + s2.marks) / 2;
  cout << "Average Marks = " << average << endl;
}

int main()
{
  Student student1(85.5);
  Student student2(92.0);

  calculateAverage(student1, student2);

  return 0;
}
