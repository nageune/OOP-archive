//
//  student.hpp
//  kyunghyunproject
//
//  Created by Kang Kyunghyun on 2022/12/13.
//

#ifndef student_h
#define student_h
#include "person.h"

class Student : public Person{
private:
    string name;
    double gpa;
public:
    Student(string name, double gpa);
    void print();
};

#endif /* student_hpp */
