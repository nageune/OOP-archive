#include <iostream>
#include <string>
using namespace std;

class Account {
private:
  string id, name;
  int balance;
  static int balanceSum;

public:
  Account(string id = "", string name = "", int balance = 0) {
    this->id = id;
    this->name = name;
    this->balance = balance;
  }

  ~Account() {
    balanceSum += this->balance;
  }

  void setAccount(string id, string name, int balance) {
    this->id = id;
    this->name = name;
    this->balance = balance;
  }

  string getId() {
    return this->id;
  }

  int getBalanceSum() {
    return balanceSum;
  }
};

int Account::balanceSum = 0;

int main() {
  int n, cnt = 0;
  cout << "총 학생 수 입력: ";
  cin >> n;
  Account temp;
  Account *acnt = new Account[n];
  for (int i = 0; i < n; i++) {
    string id, name;
    int balance, flag = 0;
    cout << i + 1 << "번째 학생 계좌 입력 : 학번 : ";
    cin >> id;
    cout << "\n이름 : ";
    cin >> name;
    cout << "\n잔액 : ";
    cin >> balance;
    cout << "=============================\n\n";
    for (int j = 0; j < cnt; j++)
      if (id == acnt[j].getId()) {
        flag = 1;
        break;
      }
    if (flag == 1)
      break;
    acnt[i].setAccount(id, name, balance);
    cnt++;
  }
  delete[] acnt;
  cout << "회수된 금액 : " << temp.getBalanceSum() << '\n';
  return 0;
}