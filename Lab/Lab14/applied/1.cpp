#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> list;
  // vector를 1~100 사이의 random한 크기로 만들고 채우는 코드 구현
  srand(time(NULL));
  int randomInt = rand() % 100 + 1;
  list.assign(randomInt, 0);
  int cnt = -1;
  while (1) {
    cnt++;
    try {
      list.at(cnt) = cnt;
    } catch (exception &e) {
      cout << "현재 list는 " << cnt << "의 크기를 가지고 있다.\n";
      break;
    }
  }
  return 0;
}