#include <iostream>
#include <list>   // 느린 search, 빠른 pop/push
#include <vector> // 빠른 search, 느린 pop/push
using namespace std;

template <typename Iter>
void print(const Iter &iter_begin, const Iter &iter_end) {
  for (Iter iter = iter_begin; iter != iter_end; iter++)
    cout << *iter << "\t";
  cout << endl;
}

template <typename Iter>
void print_reverse(const Iter &iter_begin, const Iter &iter_end) {
  Iter iter = iter_end;
  for (--iter; iter != iter_begin; iter--)
    cout << *iter << '\t';
  cout << *iter << '\t';
  cout << endl;
}

int main() {
  vector<int> v{1, 2, 3, 4};
  list<double> l{1.1, 2.2, 3.3};
  int ary[] = {100, 200, 300, 400};

  print(begin(v), end(v));
  print(begin(l), end(l));
  print(begin(ary), end(ary));

  print_reverse(begin(v), end(v));
  print_reverse(begin(l), end(l));
  print_reverse(begin(ary), end(ary));

  return 0;
}
