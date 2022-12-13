#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void commandLoad(string boardFile, char realBoard[8][8], char finalBoard[8][8]);

void commandDisplay(ofstream &fout, char nowBoard[8][8]);

int commandTouch(char nowBoard[8][8], char realBoard[8][8], char finalBoard[8][8], int row, int col);

void minesweeper(string commands, string output);