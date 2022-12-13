#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int num = 1;
  int count = 1;
  cout.imbue(locale(""));
  while (count <= 20) {
    num *= 2;
    cout << count << '\t' << setw(10) << num << '\n';
    count++;
  }
  return 0;
}