#include <iostream>
#include <string>
using namespace std;

class Text {
private:
  string text;

public:
  Text(string);
  virtual string get() const;
  virtual void append(string);
};