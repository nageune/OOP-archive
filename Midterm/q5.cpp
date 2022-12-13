#include <iostream>
using namespace std;

int **create_integer_matrix(int);
void destroy_integer_matrix(int **, int);

int main() {
  int i, j, **M;
  M = create_integer_matrix(4);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  destroy_integer_matrix(M, 4);
  return 0;
}

int **create_integer_matrix(int n) {
  int **m = new int *[n];
  for (int i = 0; i < n; i++)
    m[i] = new int[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      m[i][j] = i - j;
  return m;
}

void destroy_integer_matrix(int **m, int n) {
  for (int i = 0; i < n; i++)
    delete[] m[i];
  delete[] m;
}