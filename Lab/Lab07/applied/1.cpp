#include <iostream>
using namespace std;

int main() {
  string city, area, street, building, address;
  cout << "시 : ";
  cin >> city;
  cout << "구 : ";
  cin >> area;
  cout << "로 : ";
  cin >> street;
  cout << "건물명 : ";
  cin >> building;
  address = city + area + street + building;
  cout << "\n집 주소 : " << address << '\n';
  return 0;
}