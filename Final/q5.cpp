#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class VectorList {
  vector<double *> vItem; // Item (array)의 pointer저장
  vector<int> vLength;    // 각 Item(array)의 길이 저장
public:
  ~VectorList() {
    for (int i = 0; i < vItem.size() - 1; i++)
      delete vItem[i];
  }
  void append(double *_pArray, int _length) {
    vItem.push_back(_pArray);
    vLength.push_back(_length);
  }
  int findVector(double *_pArray, int _length) {
    for (int i = 0; i < vItem.size(); i++) {
      if (vLength[i] == _length) {
        int cnt = 0;
        for (int j = 0; j < _length; j++) {
          if (vItem[i][j] == _pArray[j])
            cnt++;
        }
        if (cnt == _length)
          return i;
      }
    }
    return -1;
  }
  void print_single_vector(int idx) {
    if (idx >= vItem.size()) {
      cout << "[Wrong index]\n";
    } else {
      cout << idx << "-th vector :";
      for (int i = 0; i < vLength[idx]; i++) {
        cout << setw(10) << vItem[idx][i];
      }
      cout << '\n';
    }
  }
  void print_all_vectors() {
    for (int idx = 0; idx < vItem.size(); idx++)
      print_single_vector(idx);
  }
};

int main() {
  VectorList vectorList;
  double *pTemp = new double[3]{1.1, 2.2, 3.3};
  vectorList.append(pTemp, 3); // 아이템 추가

  pTemp = new double[5]{10.1, 10.2, 10.3, 10.4, 10.5};
  vectorList.append(pTemp, 5); // 아이템 추가

  pTemp = new double[2]{4.5, 5.5};
  vectorList.append(pTemp, 2); // 아이템 추가

  vectorList.print_single_vector(-1); // 1) -1번째 index의 vector를 화면에 출력
  vectorList.print_single_vector(0);  // 2)  0번째 index의 vector를 화면에 출력
  cout << endl;

  vectorList.print_all_vectors(); // 3) 모든 vector들을 화면에 출력
  cout << endl;

  double *pTemp1 = new double[2]{4.5, 5.5};
  double *pTemp2 = new double[4]{1.1, 2.2, 5.5, 4.4};

  cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
  cout << "Index of vector{1.1, 2.2, 5.5, 4.4} :" << vectorList.findVector(pTemp2, 4) << endl;

  delete[] pTemp;
  delete[] pTemp1;
  delete[] pTemp2;

  return 0;
}
