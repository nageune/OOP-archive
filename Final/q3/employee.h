#ifndef employee_h
#define employee_h
#include "person.h"

class Employee : public Person {
private:
    string name;
    double salary;
public:
    Employee(string name, double salary);
    void print();
};

#endif /* employee_h */
