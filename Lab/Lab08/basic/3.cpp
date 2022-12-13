#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &v) {
  for (unsigned i = 0; i < v.size(); i++)
    cout << v[i] << "\t";
  cout << endl;
}

int main() {
  vector<int> vec{10, 20, 30};
  // vec.push_back(10);
  // vec.push_back(20);
  // vec.push_back(30);
  print(vec);

  vec[0] = 100;
  vec.at(1) = 200;
  print(vec);

  vec.push_back(400);
  print(vec);

  vec.pop_back();
  print(vec);

  cout << endl;
  for (int &elem : vec) {
    cout << "enter an element of vector v: ";
    cin >> elem;
  }

  cout << endl
       << "[ vector v ]" << endl;
  for (int elem : vec)
    cout << elem << "\t";
  cout << endl;

  return 0;
}