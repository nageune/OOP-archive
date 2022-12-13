#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Roster {
  vector<string> *names;
public:
  Roster();
  void addStudent(string name);
  void print();
};
