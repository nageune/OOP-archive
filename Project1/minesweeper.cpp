#include "minesweeper.h"

void commandLoad(string boardFile, char realBoard[8][8], char finalBoard[8][8]) {
  ifstream fin(boardFile);
  string boardLine;
  int cnt = 0;
  while (getline(fin, boardLine)) {
    // boardLine = boardLine.substr(0, boardLine.length() - 1); // 개행 \r 제거 (mac에선 주석 해제)
    for (int i = 0; i < 8; i++) { // Initializing
      realBoard[cnt][i] = boardLine[i];
      if (boardLine[i] == '*')
        finalBoard[cnt][i] = '@';
      else
        finalBoard[cnt][i] = boardLine[i];
    }
    cnt++;
  }
  fin.close();
}

void commandDisplay(ofstream &fout, char nowBoard[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)
      fout << nowBoard[i][j];
    fout << '\n';
  }
  fout << '\n';
}

int commandTouch(char nowBoard[8][8], char realBoard[8][8], char finalBoard[8][8], int row, int col) {
  if (realBoard[row][col] == '*') { // Losing Condition
    nowBoard[row][col] = '*';
    finalBoard[row][col] = '*';
    return -1;
  } else {
    int cnt = 0;
    for (int i = row - 1; i <= row + 1; i++)
      for (int j = col - 1; j <= col + 1; j++)
        if (i >= 0 && i <= 7 && j >= 0 && j <= 7 && realBoard[i][j] == '*')
          cnt++;
    nowBoard[row][col] = (char)cnt + 48;
    finalBoard[row][col] = (char)cnt + 48;
    int emptyCnt = 0; // Winning Condition
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (nowBoard[i][j] == '.')
          emptyCnt++;
    if (emptyCnt == 0)
      return 1;
    return 0;
  }
}

void minesweeper(string commands, string output) {
  ifstream fin(commands);
  ofstream fout(output);
  string line, commandText = "";
  char nowBoard[8][8], realBoard[8][8], finalBoard[8][8];
  for (int i = 0; i < 8; i++) // Initializing
    for (int j = 0; j < 8; j++) {
      nowBoard[i][j] = '.';
      finalBoard[i][j] = '.';
    }

  int touchCnt = 0;
  while (getline(fin, line)) { // Reading Commands
    // line = line.substr(0, line.length() - 1); // 개행 \r 제거 (mac에선 주석 해제)
    commandText += line + '\n';
  }
  fin.close();

  int index = 0, lineSeperatorIndex = commandText.find('\n');
  while (lineSeperatorIndex != string::npos) {
    string commandLine = commandText.substr(index, lineSeperatorIndex - index);
    fout << "Command: " << commandLine << '\n';
    string command;
    int commandIndex = 0, whiteSpaceIndex = commandLine.find(' ');
    if (whiteSpaceIndex != string::npos) // Command 구분
      command = commandLine.substr(0, whiteSpaceIndex);
    else
      command = commandLine;

    if (command == "load") { // Call Load Command
      string boardFile = commandLine.substr(whiteSpaceIndex + 1, commandLine.length() - whiteSpaceIndex - 1);
      commandLoad(boardFile, realBoard, finalBoard);
    } else if (command == "display") { // Call Display Command
      commandDisplay(fout, nowBoard);
    } else if (command == "touch") { // Call Touch Command
      touchCnt++;
      int row = commandLine[whiteSpaceIndex + 1] - '0', col = commandLine[whiteSpaceIndex + 3] - '0';
      int touchReturn = commandTouch(nowBoard, realBoard, finalBoard, row - 1, col - 1);
      if (touchReturn == 1 || touchReturn == -1) // Game Over Condition
        break;
    }

    index = lineSeperatorIndex + 1;
    lineSeperatorIndex = commandText.find('\n', index);
  }

  fout << "Game Over\n~~~~~~~~~\nFinal Board\n";
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)
      fout << finalBoard[i][j];
    fout << '\n';
  }
  fout << "\nSpaces touched: " << touchCnt << '\n';
  fout.close();
}

int main() {
  cout << "Testing minesweeper" << endl;
  minesweeper(".\\test1commands.txt", "test1_output_mine.txt");
  minesweeper(".\\test2commands.txt", "test2_output_mine.txt");
  minesweeper(".\\test3commands.txt", "test3_output_mine.txt");
  minesweeper(".\\test4commands.txt", "test4_output_mine.txt");
  minesweeper(".\\test5commands.txt", "test5_output_mine.txt");
  minesweeper(".\\test6commands.txt", "test6_output_mine.txt");
  minesweeper(".\\test7commands.txt", "test7_output_mine.txt");
  minesweeper(".\\test8commands.txt", "test8_output_mine.txt");
  minesweeper(".\\test9commands.txt", "test9_output_mine.txt");
  minesweeper(".\\test10commands.txt", "test10_output_mine.txt");

  return 0;
}