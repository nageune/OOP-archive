#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Schedule {
  vector<string> *names;
public:
  Schedule();
  void addCourse(string name);
  void print();
};
