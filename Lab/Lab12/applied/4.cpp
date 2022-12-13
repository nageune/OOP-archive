#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Avengers {
public:
  Avengers() {
    name = "";
    attack_point = 0;
    defense_point = 0;
    health = 0;
  }
  ~Avengers() {}
  //캐릭터설정함수
  virtual void set(string _name, int _attack, int _defense, int _health) {}
  //공격함수
  virtual int attack() { return 0; }
  //방어함수
  virtual void defense(int _attack_point) {}
  //캐릭터정보출력함수
  virtual void print_info() {}

protected:
  string name;       // 캐릭터 이름
  int attack_point;  // 공격력
  int defense_point; // 방어력
  int health;        // 체력
};

class Character : public Avengers {
public:
  void set(string _name, int _attack, int _defense, int _health) {
    Avengers::name = _name;
    Avengers::attack_point = _attack;
    Avengers::defense_point = _defense;
    Avengers::health = _health;
  }
  int attack() { return Avengers::attack_point; }
  void defense(int _attack_point) { Avengers::health -= _attack_point - Avengers::defense_point; }
  void print_info() {
    cout << "Name: " << Avengers::name << endl;
    cout << "Attack_Point: " << Avengers::attack_point << endl;
    cout << "Defense_Point: " << Avengers::defense_point << endl;
    cout << "Health: " << Avengers::health << endl;
  }
  int get_health() { return health; }
};

int main() {
  Character my_char;
  Character enemy_char;

  string name;
  cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
  cin >> name;

  if (name == "IronMan")
    my_char.set("IronMan", 70, 40, 100);
  else if (name == "CaptainAmerica")
    my_char.set("CaptainAmerica", 60, 50, 100);
  else if (name == "Thor")
    my_char.set("Thor", 80, 30, 100);

  srand(time(NULL));
  int randomInt = rand() % 3;

  if (randomInt == 0)
    enemy_char.set("IronMan", 70, 40, 100);
  else if (randomInt == 1)
    enemy_char.set("CaptainAmerica", 60, 50, 100);
  else if (randomInt == 2)
    enemy_char.set("Thor", 80, 30, 100);

  cout << "--My Character--" << endl;
  my_char.print_info();
  cout << "--Enemy Character--" << endl;
  enemy_char.print_info();

  cout << endl
       << "--Battle--" << endl;
  cout << "My Life: " << my_char.get_health() << "\t"
       << "Enemy Life:" << enemy_char.get_health() << endl;

  int myTurn = 1;
  while (1) {
    if (myTurn) {
      enemy_char.defense(my_char.attack());
      myTurn = 0;
    } else {
      my_char.defense(enemy_char.attack());
      myTurn = 1;
    }

    int myHealth = my_char.get_health(), enemyHealth = enemy_char.get_health();
    if (myHealth <= 0)
      myHealth = 0;
    else if (enemyHealth <= 0)
      enemyHealth = 0;

    cout << "My Life: " << myHealth << '\t' << "Enemy Life: " << enemyHealth << endl;
    if (myHealth == 0) {
      cout << "You Lose!" << endl;
      break;
    } else if (enemyHealth == 0) {
      cout << "You Win!" << endl;
      break;
    }
  }

  return 0;
}