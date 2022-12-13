#include <iostream>
#include <string>
using namespace std;

class Account {
private:
  string name;
  string id;
  int balance;

public:
  Account(string name = "", string id = "", int balance = 0) {
    this->name = name;
    this->id = id;
    this->balance = balance;
  }

  void finish() {
    cout << "학번: " << this->id << ", 이름: " << this->name << ", 잔액: " << this->balance << '\n';
  }

  string getName() {
    return this->name;
  }

  string getId() {
    return this->id;
  }

  int getBalance() {
    return this->balance;
  }

  void setAccount(string name, string id, int balance) {
    this->name = name;
    this->id = id;
    this->balance = balance;
  }

  Account operator+(Account acnt) {
    Account result(this->getName(), this->getId(), this->getBalance() + acnt.getBalance());
    return result;
  }

  Account operator-(Account acnt) {
    Account result(this->getName(), this->getId(), this->getBalance() - acnt.getBalance());
    return result;
  }
};

int main() {
  Account acnt[3] = {
      Account("장윤호", "2014", 10000),
      Account("김유민", "2019", 0),
      Account("박진배", "2013", 5000),
  };
  string senderId, receiverId;
  while (1) {
    cout << "돈을 보낼 학생의 학번을 입력하세요: ";
    cin >> senderId;
    if (senderId == "종료") {
      cout << "종료합니다.\n";
      for (auto e : acnt)
        e.finish();
      break;
    }
    cout << "돈을 받을 학생의 학번을 입력하세요: ";
    cin >> receiverId;
    if (senderId == receiverId)
      continue;
    int cnt = 0;
    for (auto e : acnt)
      if (senderId == e.getId() || receiverId == e.getId())
        cnt++;
    if (cnt != 2) {
      cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요.\n";
      continue;
    }
    int sender, receiver;
    for (int i = 0; i < 3; i++)
      if (senderId == acnt[i].getId())
        sender = i;
      else if (receiverId == acnt[i].getId())
        receiver = i;
    if (acnt[sender].getBalance() == 0) {
      cout << "보내는 학생의 잔액이 부족합니다.\n";
      continue;
    }
    int balance = acnt[sender].getBalance();
    acnt[receiver] = acnt[receiver] + acnt[sender];
    acnt[sender] = acnt[sender] - acnt[sender];
    cout << "보낸 학생의 잔액 => 학번: " << acnt[sender].getId() << ", 이름: " << acnt[sender].getName() << ", 잔액: " << acnt[sender].getBalance() << '\n';
    cout << "받은 학생의 잔액 => 학번: " << acnt[receiver].getId() << ", 이름: " << acnt[receiver].getName() << ", 잔액: " << acnt[receiver].getBalance() << '\n';
  }
  return 0;
}