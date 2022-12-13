#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "홀수 숫자를 하나 입력해주세요 : ";
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n, 0));
  int row = 0, col = n / 2, num = 1;

  while (num <= n * n) {
    v[row][col] = num;
    num++;
    int nextRow = row - 1, nextCol = col + 1;
    if (nextRow < 0)
      nextRow = n - 1;
    if (nextCol > n - 1)
      nextCol = 0;
    if (v[nextRow][nextCol] != 0) {
      row++;
    } else {
      row--;
      col++;
    }
    if (row < 0)
      row = n - 1;
    if (col > n - 1)
      col = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(4) << v[i][j];
    }
    cout << '\n';
  }
  return 0;
}