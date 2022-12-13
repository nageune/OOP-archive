#include <iostream>
using namespace std;
// sizeof 연산자는 자료형 또는 변수를 가지고 크기를 byte 단위로 반환하는 연산자
int main()
{
  unsigned short siX; // (int) 생략 가능
  unsigned iX;
  long liX;
  long long lliX;
  cout << "sizeof(siX):" << sizeof(siX) << endl;
  cout << "sizeof(iX):" << sizeof(iX) << endl;
  cout << "sizeof(liX):" << sizeof(liX) << endl;
  cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
