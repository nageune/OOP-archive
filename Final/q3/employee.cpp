#include "employee.h"

Employee::Employee(string name, double salary)  : Person::Person(name) {
    this->name = name;
    this->salary = salary;
}

void Employee::print() {
    cout << "이름: " << this->name << '\n';
    cout << "급여: " << this->salary << '\n';
}
