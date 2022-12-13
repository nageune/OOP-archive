#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int getRandomInt() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(-9, 9);
  return dis(gen);
}

void initMatrix(vector<vector<int>> &M, int row, int col) {
  for (int i = 0; i < row; i++) {
    vector<int> temp;
    for (int j = 0; j < col; j++)
      temp.push_back(getRandomInt());
    M.push_back(temp);
  }
}

void printMatrix(vector<vector<int>> M, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << setw(4) << M[i][j];
    cout << '\n';
  }
  cout << '\n';
}

void multMatrix(vector<vector<int>> A, vector<vector<int>> B, int aRow, int aCol, int bRow, int bCol) {
  vector<vector<int>> result;
  for (int k = 0; k < aRow; k++) {
    vector<int> temp;
    for (int i = 0; i < bCol; i++) {
      int sum = 0;
      for (int j = 0; j < aCol; j++)
        sum += A[k][j] * B[j][i];
      temp.push_back(sum);
    }
    result.push_back(temp);
  }
  printMatrix(result, aRow, bCol);
}

int main() {
  vector<vector<int>> A, B;
  int aRow, aCol, bRow, bCol;
  cout << "A의 행, 열의 크기를 입력해주세요 : ";
  cin >> aRow >> aCol;
  cout << "B의 행, 열의 크기를 입력해주세요 : ";
  cin >> bRow >> bCol;
  cout << '\n';
  if (!aRow || !aCol || !bRow || !bCol)
    cout << "행렬을 생성할 수 없습니다.\n";
  else {
    initMatrix(A, aRow, aCol);
    initMatrix(B, bRow, bCol);
    cout << "A 행렬 :\n";
    printMatrix(A, aRow, aCol);
    cout << "B 행렬 :\n";
    printMatrix(B, bRow, bCol);
    if (aCol == bRow) {
      cout << "AB 곱행렬 :\n";
      multMatrix(A, B, aRow, aCol, bRow, bCol);
    } else {
      cout << "두 행렬을 곱할 수 없습니다.\n";
    }
  }

  return 0;
}