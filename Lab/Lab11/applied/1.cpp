#include <cmath>
#include <iostream>
using namespace std;

class Point {
private:
  int x;
  int y;

public:
  Point(int _x = 0, int _y = 0) : x(_x), y(_y){};

  Point operator-(Point pt) {
    Point result;
    result.setPoint(this->x - pt.x, this->y - pt.y);
    return result;
  }

  Point operator*(Point pt) {
    Point result;
    result.setPoint(this->x * pt.x, this->y * pt.y);
    return result;
  }

  void setPoint(int x1, int y1) {
    x = x1;
    y = y1;
  }

  int getX() {
    return this->x;
  }

  int getY() {
    return this->y;
  }
};

int main() {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  Point *pP1, *pP2, *pP3;

  cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
  cin >> x1 >> y1;
  cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
  cin >> x2 >> y2;
  pP1 = new Point(x1, y1);
  pP2 = new Point(x2, y2);
  pP3 = new Point(); // x,y가 0으로 초기화

  /*아래의방식으로도x,y값설정이가능해야함*/
  // pP1->setPoint(x1, y1);
  // pP1->setPoint(x2, y2);
  /***********************************************/

  *pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

  /* pP3을 활용하여 거리값을 구함 */
  cout << "두좌표사이의길이는" << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;

  return 0;
}