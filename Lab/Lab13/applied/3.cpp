#include <iostream>
#include <string>
using namespace std;

int main() {
  while (1) {
    string s, r = "";
    cout << "문자열 하나를 입력해주세요 : ";
    cin >> s;
    if (s == "Q" || s == "q")
      break;
    cout << "입력하신 문자열의 역순 : ";
    for (int i = s.size() - 1; i >= 0; i--)
      r += s[i];
    cout << r << '\n';
    if (s == r)
      cout << "이 문자는 회문입니다.\n\n";
    else
      cout << "이 문자는 회문이 아닙니다.\n\n";
  }
  return 0;
}