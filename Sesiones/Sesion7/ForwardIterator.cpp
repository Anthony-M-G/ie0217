#include <iostream>
#include <forward_list>

using namespace std;

int main (int argc, char *argv[]) {
  forward_list<int> nums = {1,56,67, 34};

  forward_list<int>::iterator itr=nums.begin();

  while (itr != nums.end()) {
  int original_value = *itr;
  *itr = original_value * 2;
  itr++; // Aumenta pero en aritmética de punteros
  }
  for (int num: nums) {
  cout << num << ", ";
  }

  return 0;
}
