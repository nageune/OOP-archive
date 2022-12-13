#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ofstream ofs;
  ofs.open("temp.txt");
  // 임의의 10x10 행렬 저장 구현
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      if (j == 9)
        ofs << rand() % 100 + 1;
      else
        ofs << rand() % 100 + 1 << ' ';
    ofs << '\n';
  }
  ofs.close();

  // 파일이름 입력
  string fileName;
  cout << "파일 이름 : ";
  cin >> fileName;

  // 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현
  vector<vector<int>> v(10, vector<int>(10));
  try {
    ifstream ifs(fileName);
    if (!ifs)
      throw "File \"" + fileName + "\" not found";
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        ifs >> v[i][j];
    ifs.close();
  } catch (string err) {
    cout << err << '\n';
    exit(0);
  }

  int row, col;
  cout << "출력할 행 크기 : ";
  cin >> row;
  cout << "출력할 열 크기 : ";
  cin >> col;
  try {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++)
        cout << v.at(i).at(j) << ' ';
      cout << '\n';
    }
  } catch (std::exception &e) {
    cout << '\n'
         << e.what() << '\n';
  }
  return 0;
}