#include "Student.hpp"

Student::Student(string name) {
    this->name = name;
}
Schedule Student::getSchedule() {
    return this->schedule;
}
string Student::getName() {
    return this->name;
}
void Student::print() {
    cout << "Student name: " << this->getName() << "\nList of Courses\n";
    this->getSchedule().print();
    cout << "\n\n";
}
