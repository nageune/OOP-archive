#include "student.h"

Student::Student(string name, double gpa) : Person::Person(name) {
    this->name = name;
    this->gpa = gpa;
}
