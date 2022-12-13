#include <iostream>
using namespace std;

void square(int *n) {
  *n *= *n;
}

int main() {
  int n;
  cout << "input> ";
  cin >> n;
  square(&n);
  cout << "제곱값> " << n << endl;
  return 0;
}