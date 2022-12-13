#include "Course.hpp"

Course::Course(string name, int num) {
    this->name = name;
    this->num = num;
}
Roster Course::getRoster() {
    return this->roster;
}
string Course::getName() {
    return this->name;
}
int Course::getNum() {
    return this->num;
}
void Course::print() {
    cout << "Course name: " << this->getName() << "\nNumber of Units: " << this->getNum() << "\nList of Students\n";
    this->getRoster().print();
    cout << "\n\n";
}

