#ifndef PERSON_H

#define PERSON_H

#include <iostream>

#include <string>

using namespace std;

// Person 클래스의 정의

class Person {
private:
    string name;
public:
    Person (string nme);
    ~Person();
    virtual void print() const;
};

#endif
