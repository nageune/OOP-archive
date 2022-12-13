#include <iostream>
#include <vector>
using namespace std;

// void reverse(vector<int> *vec) {
//   // for (int i = 0; i < vec->size() / 2; i++) {
//   //   int temp = (*(vector<int> *)vec)[i];
//   //   (*(vector<int> *)vec)[i] = (*(vector<int> *)vec)[vec->size() - 1 - i];
//   //   (*(vector<int> *)vec)[vec->size() - 1 - i] = temp;
//   // }
//   int size = vec->size();
//   for (int i = size - 1; i >= 0; i--)
//     vec->push_back((*(vector<int> *)vec)[i]);
//   for (int i = 0; i < size; i++)
//     vec->erase(vec->begin());
// }
void reverse(vector<int> &vec) {
  int size = vec.size();
  for (int i = size - 1; i >= 0; i--)
    vec.push_back(vec[i]);
  for (int i = 0; i < size; i++)
    vec.erase(vec.begin());
}

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // for (int i = 0; i < 10; i++)
  //   vec.push_back(i + 1);
  cout << "기본 Vector 값:" << endl;
  for (int elem : vec)
    cout << ' ' << elem;
  cout << endl;
  cout << "함수 실행 후 Vector 값:" << endl;
  reverse(vec);
  for (int elem : vec)
    cout << ' ' << elem;
  cout << endl;
  return 0;
}