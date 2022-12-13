#include "Schedule.hpp"

class Student {
	string name;
	Schedule schedule;
public:
	Student(string name);
	Schedule getSchedule();
	string getName();
	void print();
};
