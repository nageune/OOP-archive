#include <iostream>
using namespace std;

int main() {
  char grade = 'X';
  int score;
  cout << "Enter your score: ";
  cin >> score;
  if (score >= 90 && score <= 100) {
    grade = 'A';
    cout << "Your grade is " << grade << endl;
  } else if (score >= 80 && score <= 90) {
    grade = 'B';
    cout << "Your grade is " << grade << endl;
  } else if (score >= 70 && score <= 80) {
    grade = 'C';
    cout << "Your grade is " << grade << endl;
  } else if (score >= 60 && score <= 70) {
    grade = 'D';
    cout << "Your grade is " << grade << endl;
  } else if (score < 60 && score >= 0) {
    grade = 'F';
    cout << "Your grade is " << grade << endl;
  } else {
    cout << "The score (" << score << ") is invalid" << endl;
  }
  return 0;
}