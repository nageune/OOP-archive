
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void get_command(string &command);

void get_size(int &size);

int **gen_matrix(int size);

void swap(int *a, int *b); // 주어짐

void sort_array(int *ary, int size);

void sort_matrix_row(int **matrix, int size);

void print_matrix(int **matrix, int size);

void save_matrix(int **matrix, int size);

void free_matrix(int **matrix, int size);

int main() {
  string command;
  int **matrix = NULL;
  int size = 0;
  while (1) {
    get_command(command);
    if (command == "1") {
      get_size(size);
      matrix = gen_matrix(size);
    } else if (command == "2") {
      print_matrix(matrix, size);
    } else if (command == "3") {
      sort_matrix_row(matrix, size);
    } else if (command == "4") {
      save_matrix(matrix, size);
    } else if (command == "0") {
      free_matrix(matrix, size);
      cout << "Exit the program.." << endl;
      exit(104);
    } else {
      cout << "Wrong command" << endl
           << endl;
    }
  }

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort_array(int *ary, int size) {
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - 1; j++)
      if (ary[j] > ary[j + 1])
        swap(ary[j], ary[j + 1]);
}

void get_command(string &command) {
  cout << "1. Generate matrix\n";
  cout << "2. Print matrix\n";
  cout << "3. Sort matrix\n";
  cout << "4. Save matrix\n";
  cout << "0. Exit program\n>>";
  cin >> command;
}

void get_size(int &size) {
  cout << "Enter the size in (size x size): ";
  cin >> size;
  cout << '\n';
}

int **gen_matrix(int size) {
  int **matrix = new int *[size];
  for (int i = 0; i < size; i++)
    matrix[i] = new int[size];
  srand(time(NULL));
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      matrix[i][j] = rand() % 100 + 1;
  return matrix;
}

void sort_matrix_row(int **matrix, int size) {
  for (int i = 0; i < size; i++)
    sort_array(matrix[i], size);
  cout << "Completed\n\n";
}

void print_matrix(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      cout << setw(4) << matrix[i][j];
    cout << '\n';
  }
  cout << '\n';
}

void save_matrix(int **matrix, int size) {
  ofstream fout("matrix.txt");
  fout << size << '\n';
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      fout << setw(4) << matrix[i][j];
    fout << '\n';
  }
  cout << "Saved\n\n";
}

void free_matrix(int **matrix, int size) {
  for (int i = 0; i < size; i++)
    delete[] matrix[i];
  delete[] matrix;
}