#include "FixedText.h"

FixedText::FixedText() : Text::Text("FIXED") {}
void FixedText::append(string _extra) override {}

int main() {
  FixedText t3;
  t3.append("A");
  cout << t3.get() << endl;
  t1 = t2; // Base <- Derived 가능
  // t2 = t1; // Derived <- Base 불가능
  return 0;
}