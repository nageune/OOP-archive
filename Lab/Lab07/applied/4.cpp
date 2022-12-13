#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream fin1("input1.txt");
  ifstream fin2("input2.txt");
  string input1 = "", input2 = "", line;
  while (getline(fin1, line))
    input1 += line + '\n';
  while (getline(fin2, line))
    input2 += line + '\n';
  fin1.close();
  fin2.close();

  ofstream fout("output.txt");
  fout << input1 << '\n'
       << input2;
  fout.close();
  return 0;
}