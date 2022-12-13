#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream fin("input.txt");
  string input = "", line, result = "";
  while (getline(fin, line))
    input += line + ' ';

  int length;
  cout << "length = ";
  cin >> length;
  for (int i = 0; i < input.length(); i++) {
    result += input[i];
    if ((i + 1) % length == 0)
      result += '\n';
  }

  ofstream fout("result.txt");
  fout << result;
  fout.close();
  return 0;
}