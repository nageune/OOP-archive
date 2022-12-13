#include <iostream>
#include <random>
using namespace std;

int getRandomInt(int n) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, n);
  return dis(gen);
}

void checkDuplicate(int *arr, int n) {
  for (int i = 0; i < n / 2; i++) {
    int cnt = 0;
    for (int j = 0; j < n / 2; j++) {
      if (arr[i] == arr[j])
        cnt++;
    }
    if (cnt != 1) {
      cout << "\nDuplicates found.\n\n";
      return;
    }
  }
  cout << "\nDuplicates not found.\n\n";
}

int main() {
  while (1) {
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    if (n >= 2) {
      cout << "Size of random array: " << n / 2;

      int *arr = new int[n / 2];
      for (int i = 0; i < n / 2; i++)
        arr[i] = getRandomInt(n);

      cout << "\n[ Array ]\n";
      for (int i = 0; i < n / 2; i++)
        cout << arr[i] << ' ';

      checkDuplicate(arr, n);

    } else {
      cout << "Wrong number!!!\n";
      break;
    }
  }
  return 0;
}