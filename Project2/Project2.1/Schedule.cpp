#include "Schedule.hpp"

Schedule::Schedule() {
  this->names = new vector<string>;
}

void Schedule::addCourse(string name) {
  (*names).push_back(name);
}

void Schedule::print() {
  for (string elem : *names) {
    cout << elem << '\n';
  }
}
