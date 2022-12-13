#include <iostream>
#include <vector>
using namespace std;

int inputGrade(float grade) {
  cin >> grade;
  if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
    cout << "invalid input!!!" << endl;
    exit(EXIT_FAILURE);
  } else
    return (int)grade;
}

int topGrade(const vector<int> &grade) {
  int top = grade[0];
  for (int elem : grade)
    if (elem > top)
      top = elem;
  return top;
}

int main() {
  vector<int> grades;
  float _grade = 0;
  for (int i = 0; i < 3; i++) {
    cout << "Input " << i << "-th grade(0~100):";
    int grade = inputGrade(_grade);
    grades.push_back(grade);
  }
  int top = topGrade(grades);
  cout << "Top Grade: " << top << endl;
  return 0;
}