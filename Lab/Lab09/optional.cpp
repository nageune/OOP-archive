#include <fstream>
#include <iostream>
using namespace std;

bool atoi(istream &input, ostream &output) {
  char s[10000] = "";
  bool check = false;
  while (input.getline(s, 10000)) {
    int i = 0;
    while (s[i] != EOF) {
      if (s[i] == ' ') {
        char tmp[10000] = "";
        for (int j = i + 1; (s[j] > 47) && (s[j] < 58); j++) {
          tmp[j - i - 1] = s[j];
          check = true;
        }
        for (int j = 0; tmp[j] != '\0'; j++) {
          output << tmp[j];
          i++;
        }
        if ((tmp[0] > 47) && (tmp[0] < 58)) {
          output << '\n';
        }
      }
      i++;
    }
  }
  return check;
}

int main() {
  cout << "Please enter anything : " << endl;
  bool bHasDecimal = atoi(cin, cout);
  if (bHasDecimal) {
    cout << "We Found Decimal!" << endl;
  } else {
    cout << "No Decimal Found." << endl;
  }
  ifstream inputFile;
  inputFile.open("input.txt");
  ofstream outputFile;
  outputFile.open("output.txt");
  bHasDecimal = atoi(inputFile, outputFile);
  if (bHasDecimal) {
    cout << "We Found Decimal!" << endl;
  } else {
    cout << "No Decimal Found." << endl;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}