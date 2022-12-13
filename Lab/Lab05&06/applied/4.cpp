#include <iostream>
using namespace std;

int main() {
  int n;
  while (1) {
    cout << "단 수를 입력하세요: ";
    cin >> n;
    if (n == -1) {
      cout << "종료합니다." << '\n';
      break;
    } else if (n < 1 || n > 9) {
      cout << "1 부터 9까지의 정수를 입력해주세요." << '\n';
    } else {
      for (int i = 1; i <= 9; i++) {
        cout << n << '*' << i << " = " << n * i << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}