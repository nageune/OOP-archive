#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class Point {
public:
  T x;
  T y;
  Point(T x, T y);
  bool operator==(const Point &point);
};

template <typename T>
Point<T>::Point(T x, T y) {
  this->x = x;
  this->y = y;
}

template <typename T>
bool Point<T>::operator==(const Point &point) {
  if (this->x == point.x && this->y == point.y)
    return true;
  return false;
}

void get_command(string &command) {
  do {
    cout << "1. Print\n";
    cout << "2. Find Points\n";
    cout << "0. Exit\n";
    cout << "Input>> ";
    cin >> command;
  } while (command != "1" && command != "2" && command != "0");
}

template <typename T>
void count_val(Point<T> *begin, Point<T> *end) {
  int x, y, cnt = 0;
  cout << "Enter (x, y): ";
  cin >> x >> y;
    Point<T> temp(x,y);
  for (auto iter = begin; iter != end; iter++)
    if (*iter == temp)
      cnt++;
  cout << "Number of matching elements: " << cnt << "\n";
}

int main() {
  Point<int> myPoints[] = {{1, 2}, {-1, 5}, {3, 7}, {2, 4}, {1, 10}, {1, 2}};
  string command;

  while (1) {
    get_command(command);
    if (command == "1")
      for_each(begin(myPoints), end(myPoints), [](auto &point) { cout << "(" << point.x << ", " << point.y << ")\n"; });
    else if (command == "2")
      count_val<int>(begin(myPoints), end(myPoints));
    else if (command == "0")
      break;
  }
  cout << "Exit program.." << endl;
  return 0;
}
