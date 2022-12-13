#include "Text.h"

Text::Text(string _t) : text(_t) {}
string Text::get() const { return text; }
void Text::append(string _extra) { text += _extra; }

int main() {
  Text t1("Plain");
  t1.append("A");
  cout << t1.get() << endl;
  return 0;
}