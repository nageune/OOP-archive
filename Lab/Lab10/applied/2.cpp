#include <iostream>
#include <string>
using namespace std;

class CStudent {
private:
  int number;
  string name;
  string major;

public:
  CStudent() : number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
  CStudent(int _number, string _name, string _major) {
    number = _number;
    name = _name;
    major = _major;
  }

  void setNumber(int _number) {
    number = _number;
  }

  void setName(string _name) {
    name = _name;
  }

  void setMajor(string _major) {
    major = _major;
  }

  int getNumber() {
    return number;
  }

  string getName() {
    return name;
  }

  string getMajor() {
    return major;
  }

  void Display() {
    cout << "학번 :" << number << '\n';
    cout << "이름 :" << name << '\n';
    cout << "전공 :" << major << "\n\n";
  }
};

int main() {
  CStudent s[3];                // 3명의 학생정보를 저장할 class 배열
  int inputNumber;              // 키보드로 학번을 입력 받을 변수
  string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
  int length = 0;               //현재입력된학생의수

  while (1) {
    if (length == 3)
      break;
    cout << length + 1 << " 번째 학생 입력\n";
    cout << "학번 : ";
    cin >> inputNumber;
    cout << "이름 : ";
    cin >> inputName;
    cout << "전공 : ";
    cin >> inputMajor;
    bool dup = false;
    for (int i = 0; i < length; i++)
      if (inputNumber == s[i].getNumber()) {
        cout << "※중복된 학번이 존재합니다\n\n";
        dup = true;
        break;
      }
    if (!dup) {
      s[length].setNumber(inputNumber);
      s[length].setName(inputName);
      s[length].setMajor(inputMajor);
      cout << "※입력 완료\n\n";
      length++;
    }
    if (length == 3)
      cout << "----모든입력이 완료되었습니다----\n";
  }
  cout << "1학생정보\n";
  cout << "학번 :" << s[0].getNumber() << '\n';
  cout << "이름 :" << s[0].getName() << '\n';
  cout << "전공 :" << s[0].getMajor() << "\n\n";
  cout << "2학생정보\n";
  cout << "학번 :" << s[1].getNumber() << '\n';
  cout << "이름 :" << s[1].getName() << '\n';
  cout << "전공 :" << s[1].getMajor() << "\n\n";
  cout << "3학생정보\n";
  cout << "학번 :" << s[2].getNumber() << '\n';
  cout << "이름 :" << s[2].getName() << '\n';
  cout << "전공 :" << s[2].getMajor() << "\n\n";
  return 0;
}