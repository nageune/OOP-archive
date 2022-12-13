#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <string>
#include <iostream>
#include <cassert>
#include "builder.h"
#include "Package1.hpp"
#include "Package2.hpp"
#include "Package3.hpp"
using namespace std;

// 정적 멤버를 갖는 Director 클래스
class  Director
{
  public:
    static Vacation* vacation;
    static void book(int type); // 클라이언트는 이 함수만 호출 가능
};
#endif  
