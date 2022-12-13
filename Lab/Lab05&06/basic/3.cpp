#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int column = 1, row = 1;
  while (column <= 10) {
    while (row <= 10) {
      int num;
      if (column == row) {
        num = 1;
      } else {
        num = 0;
      }
      cout << setw(4) << num;
      row++;
    }
    cout << endl;
    row = 1;
    column++;
  }
  return 0;
}