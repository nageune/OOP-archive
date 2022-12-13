#include <iostream>
using namespace std;

int main() {
  char key;
  cout << "Enter a key (p or q): ";
  cin >> key;
  switch (key) {
  case 'p':
  case 'P':
    cout << "Pause" << '\n';
    break;
  case 'q':
  case 'Q':
    cout << "Quit" << '\n';
    break;
  default:
    cout << "Default" << '\n';
  }
  return 0;
}