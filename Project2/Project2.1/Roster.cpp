#include "Roster.hpp"

Roster::Roster() {
  this->names = new vector<string>;
}

void Roster::addStudent(string name) {
  (*names).push_back(name);
}

void Roster::print() {
  for (string elem : *names) {
    cout << elem << '\n';
  }
}
