#include <iostream>
using namespace std;

int main() {
  int n;
  for (int i = 1; i <= 5; i++) {
    cout << i << "번째 정수 : ";
    cin >> n;
    if (n % 2 == 0) {
      cout << n << "은(는) 짝수입니다." << '\n';
    } else {
      cout << n << "은(는) 홀수입니다." << '\n';
    }
  }
  return 0;
}