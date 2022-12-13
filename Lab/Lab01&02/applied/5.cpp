#include <iostream>
using namespace std;

int main()
{
  int Fahrenheit, Celsius;

  cout << "Please enter Fahrenheit value: ";
  cin >> Fahrenheit;
  cout << "Celsius value is " << 5.0f / 9.0f * (Fahrenheit - 32) << endl;
}