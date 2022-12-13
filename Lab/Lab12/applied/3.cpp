#include <iostream>
using namespace std;

class Train {
public:
  Train() {}
  Train(int people) {
    mPeople = people;
  }
  ~Train() {}
  virtual int station(int takeOff, int takeOn) {
    return mPeople += takeOn - takeOff;
  }

protected:
  int mPeople; // 사람 수
};

class Ktx : public Train {
public:
  Ktx() : Train::Train(0) {}
  Ktx(int people) : Train::Train(people) {}
  ~Ktx() {}
  //기차에사람이타고내리는함수
  int station(int takeOff, int takeOn) {
    return Train::mPeople += takeOn - takeOff;
  }
  int getPeople() {
    return Train::mPeople;
  }
};
int main() {
  Ktx k;
  int max = 0, flag = 0;
  for (int i = 0; i < 5; i++) {
    int takeOff, takeOn;
    cout << i + 1 << "번역: ";
    cin >> takeOff >> takeOn;
    if (k.getPeople() < takeOff) {
      cout << "정원미달입니다" << endl;
      flag = 1;
      break;
    } else if (k.getPeople() + takeOn > 300) {
      cout << "정원초과입니다" << endl;
      flag = 1;
      break;
    }
    k.station(takeOff, takeOn);
    if (max < k.getPeople())
      max = k.getPeople();
  }
  if (flag == 0)
    cout << "가장 많은 사람이 탑승 했을 때의 사람 수: " << max << endl;
  return 0;
}