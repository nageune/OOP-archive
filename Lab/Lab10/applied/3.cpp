#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
  string name;
  int id;
  string dpt;
  vector<string> subject;
  vector<char> grade;

public:
  Student() : name("default"), id(0), dpt("depart") {}
  Student(string _name, int _id, string _dpt) {
    name = _name;
    id = _id;
    dpt = _dpt;
  }

  void setName(string _name) {
    name = _name;
  }

  void setID(int _id) {
    id = _id;
  }

  void setDpt(string _dpt) {
    dpt = _dpt;
  }

  void print() {
    cout << name << ' ' << id << ' ' << dpt << '\n';
  }

  void addGrade(string _subject, char _grade) {
    subject.push_back(_subject);
    grade.push_back(_grade);
  }

  void printGrades() {
    for (int i = 0; i < subject.size(); i++)
      cout << subject[i] << ' ' << grade[i] << '\n';
    cout << "GPA : " << getGPA() << '\n';
  }

  float getGPA() {
    float value = 0;
    for (char i : grade) {
      if (i == 'A')
        value += 4;
      else if (i == 'B')
        value += 3;
      else if (i == 'C')
        value += 2;
      else if (i == 'D')
        value += 1;
    }
    return value / grade.size();
  }

  void getYear(int year) {
    int temp = year - id / 1000000 + 1;
    if (temp == 1)
      cout << "Freshmen(1학년)\n";
    else if (temp == 2)
      cout << "Sophomore(2학년)\n";
    else if (temp == 3)
      cout << "Junior(3학년)\n";
    else if (temp == 4)
      cout << "Senior(4학년)\n";
    else
      cout << "About to graduate(5학년 이상)\n";
  }
};

int main() {
  Student Harry("Harry", 2017310973, "CS");
  Harry.print();
  Harry.getYear(2019);
  Harry.addGrade("programming", 'A');
  Harry.addGrade("Basic Circuit", 'B');
  Harry.printGrades();
  cout << "\n\n";

  Student Ron;
  Ron.print();
  cout << "\n";
  Ron.setName("Ron");
  Ron.setID(2014103959);
  Ron.setDpt("EE");
  Ron.print();
  Ron.getYear(2019);
  Ron.addGrade("Computer Architecture", 'B');
  Ron.addGrade("Maching Learning", 'B');
  Ron.addGrade("Computer Vision", 'C');
  Ron.printGrades();
  cout << "\n\n";

  return 0;
}