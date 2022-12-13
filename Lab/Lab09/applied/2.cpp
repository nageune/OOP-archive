#include <iostream>
using namespace std;

int *make_arr(int n) {
  int *temp = new int[n];
  for (int i = 0; i < n; i++)
    temp[i] = (i + 1) * 2 - 1;
  return temp;
}

void print_arr(int *a, int n) {
  cout << "\nOdd Number Array:" << endl;
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
}

int sum_arr(int *a, int n) {
  int s = 0;
  while (n--) {
    s += *a;
    a++;
  }
  return s;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;

  int *arr = make_arr(n);
  print_arr(arr, n);

  int sum = sum_arr(arr, n);
  cout << "\nSum of the array: " << sum << endl;

  delete[] arr;
  return 0;
}