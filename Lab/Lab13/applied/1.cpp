#include <iostream>
using namespace std;

typedef int type;

template <typename T>
class CList {
public:
  CList() { m_Length = 0; }
  ~CList() {}

  bool IsEmpty() { // list가비어있으면1,아니면0
    if (m_Length == 0)
      return true;
    return false;
  }
  bool IsFull() { // list가 꽉 차 있으면 1, 아니면 0
    if (m_Length == 5)
      return true;
    return false;
  }

  void Add(T data) { // list에 데이터 추가
    if (m_Length == 5) {
      cout << "\tList is full.\n";
      return;
    }
    for (int i = 0; i < m_Length; i++) {
      if (m_Array[i] == data) {
        cout << "\t중복된 데이터가 존재합니다.\n";
        return;
      }
    }
    m_Array[m_Length] = data;
    m_Length++;
    sort(m_Array, m_Array + m_Length);
  }
  void Delete(T data) { // list에 데이터 삭제
    if (m_Length == 0) {
      cout << "\tList is empty.\n";
      return;
    }
    for (int i = 0; i < m_Length; i++)
      if (m_Array[i] == data)
        m_Array[i] = 2147483647;
    sort(m_Array, m_Array + m_Length);
    m_Length--;
  }
  void Print() { // list에 데이터 출력
    cout << "\t※ Current List\n\t";
    for (int elem : m_Array)
      cout << elem << ' ';
    cout << '\n';
  }

private:
  T m_Array[5];
  int m_Length;
};

int command() {
  int num;
  cout << "\n\t---- menu ----" << endl;
  cout << "\t1. 리스트 추가" << endl;
  cout << "\t2. 리스트 삭제" << endl;
  cout << "\t3. 리스트 출력" << endl;
  cout << "\t4. 프로그램 종료" << endl;
  cout << "\n\t입력 --> ";
  cin >> num;
  return num;
}

int main() {
  CList<type> list; // type형으로 list 선언
  type input;       // list에 입력 할 데이터
  int com;          // 선택한 기능
  while (1) {
    com = command(); // 기능을 선택
    switch (com) {
    case 1: // 추가
      cout << "\n추가할 데이터 : ";
      cin >> input;
      list.Add(input);
      break;
    case 2: // 삭제
      cout << "\n삭제할 데이터 : ";
      cin >> input;
      list.Delete(input);
      break;
    case 3: // 출력
      list.Print();
      break;
    case 4: // 프로그램 종료
      cout << "\n\t프로그램을 종료합니다\n";
      return 0;
      break;
    default:
      break;
    }
  }
  return 0;
}