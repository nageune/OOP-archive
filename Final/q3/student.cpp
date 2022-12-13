#include "student.h"

Student::Student(string name, double gpa) : Person::Person(name) {
    this->name = name;
    this->gpa = gpa;
}

void Student::print() {
    cout << "이름: " << this->name << '\n';
    cout << "GPA: " << this->gpa << '\n';
}
