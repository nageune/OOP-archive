#include "Roster.hpp"

class Course {
    string name;
    int num;
    Roster roster;
public:
    Course(string name, int num);
    Roster getRoster();
    string getName();
    int getNum();
    void print();
};
