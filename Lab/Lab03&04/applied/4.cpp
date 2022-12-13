#include <iostream>
using namespace std;

void get_data(int &a, int &b)
{
  cout << "x 입력 : ";
  cin >> a;
  cout << "y 입력 : ";
  cin >> b;
}

void swap_call_by_value(int x, int y)
{
  int temp = x;
  x = y;
  y = temp;
}

void swap_call_by_reference(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int main()
{
  int x, y;
  get_data(x, y);

  cout << "\n"
       << "swap_call_by_value 함수 사용 전" << endl;
  cout << "x = " << x << ", y = " << y << endl;
  swap_call_by_value(x, y);
  cout << "swap_call_by_value 함수 사용 후" << endl;
  cout << "x = " << x << ", y = " << y << endl;

  cout << "\n"
       << "swap_call_by_reference 함수 사용 전" << endl;
  cout << "x = " << x << ", y = " << y << endl;
  swap_call_by_reference(x, y);
  cout << "swap_call_by_reference 함수 사용 후" << endl;
  cout << "x = " << x << ", y = " << y << endl;
}