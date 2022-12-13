#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v1(10), v2(10);
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    v1[i] = rand() % 11;
    v2[i] = rand() % 21;
  }
  int max = 0, min = 200;
  for (auto v1Iter = v1.begin(); v1Iter != v1.end(); v1Iter++)
    for (auto v2Iter = v2.begin(); v2Iter != v2.end(); v2Iter++) {
      if (*v1Iter * *v2Iter > max)
        max = *v1Iter * *v2Iter;
      if (*v1Iter * *v2Iter < min)
        min = *v1Iter * *v2Iter;
    }
  cout << "<vector 1>\n";
  for (auto iter = v1.begin(); iter != v1.end(); iter++)
    cout << *iter << ' ';
  cout << "\n<vector 2>\n";
  for (auto iter = v2.begin(); iter != v2.end(); iter++)
    cout << *iter << ' ';
  cout << "\n\n최댓값 = " << max << "\n최솟값 = " << min << '\n';
  return 0;
}