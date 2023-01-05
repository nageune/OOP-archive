#ifndef student_h
#define student_h
#include "person.h"

class Student : public Person {
private:
    string name;
    double gpa;
public:
    Student(string name, double gpa);
    void print() const override;
};

#endif /* student_hpp */
