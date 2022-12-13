#include "director.h"

// 정적 데이터 멤버 정의
Vacation*  Director::vacation = 0;
// 클라이언트가 호출할 정적 멤버 함수 정의
void Director::book(int packageType)
{
  if(packageType == 1)
  {
    vacation = new Package1();
  }
  else if(packageType == 2)
  {
    vacation = new Package2();
  }
  else if(packageType == 3)
  {
    vacation = new Package3();
  }
  cout << "여행 계획에 대한 정보: " << endl;
  vacation->bookHotels();
  vacation->bookFlights();
  vacation->bookTours();
  cout << endl;
}
