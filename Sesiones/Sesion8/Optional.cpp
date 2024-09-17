#include <iostream>
#include <optional>
using namespace std;

optional<int> division(int a, int b){
  if(b==0)
    return {};
  return a/b;
}

int main (int argc, char *argv[]) {
  optional<int> result = division(2, 1);
  if(result){
    cout << result.value() << endl;
  }
  else cout << "Error: División por cero" << endl;

  return 0;
}

