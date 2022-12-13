#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;

void print(const Matrix &mat) {
  // for (vector<int> row : mat) {
  //   for (int col : row)
  //     cout << setw(4) << col;
  //   cout << endl;
  // }

  vector<int> row = mat[0];
  for (auto row : mat) {
    for (auto col : row)
      cout << setw(4) << col;
    cout << endl;
  }
}

int main() {
  Matrix mat{{1, 2, 3}, {4, 5, 6}};

  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[0][2] = 3;
  mat[1][0] = 4;
  mat[1][1] = 5;
  mat[1][2] = 6;

  print(mat);

  return 0;
}