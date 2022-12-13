#include <iostream>
#include <string>
using namespace std;

int main() {
  string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향", keyword;
  cout << "키워드 : ";
  getline(cin, keyword);
  cout << "\n검색결과 : ";
  int index = 0, comma = data.find(',');
  while (comma != string::npos) {
    string text = data.substr(index, comma - index);
    if (text.find(keyword) != string::npos)
      cout << text << ' ';
    index = comma + 1;
    comma = data.find(',', index);
  }
  cout << '\n';
  return 0;
}