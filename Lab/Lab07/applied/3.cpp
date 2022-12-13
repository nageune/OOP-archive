#include <fstream>
#include <iostream>
#include <random>
using namespace std;

int getRandomInt() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, 100);
  return dis(gen);
}

int main() {
  int a[10][10] = {0};
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      a[i][j] = getRandomInt();

  ofstream fout("random.txt");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      fout << a[i][j] << ' ';
    fout << '\n';
  }
  fout.close();
  return 0;
}