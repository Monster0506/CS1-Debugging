// Dynamically allocated 2D arrays (array of row pointers).
//
// Expected output:
//   original (2x3):
//   1 2 3
//   4 5 6
//   transposed (3x2):
//   1 4
//   2 5
//   3 6

#include <iostream>

int **makeMatrix(int rows, int cols); // all elements start at 0
void freeMatrix(int **m, int rows);
int **transpose(int **m, int rows, int cols); // result has cols rows
void printMatrix(int **m, int rows, int cols);

int main() {
  int **m = makeMatrix(2, 3);
  int value = 1;
  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 3; c++) {
      m[r][c] = value++;
    }
  }

  std::cout << "original (2x3):" << std::endl;
  printMatrix(m, 2, 3);

  int **t = transpose(m, 2, 3);
  std::cout << "transposed (3x2):" << std::endl;
  printMatrix(t, 3, 2);

  freeMatrix(m, 2);
  freeMatrix(t, 3);
}

int **makeMatrix(int rows, int cols) {
  int **m = new int[rows];
  for (int r = 0; r < rows; r++) {
    m[r] = new int[cols];
    for (int c = 0; c < cols; c++) {
      m[r][c] = 0;
    }
  }
  return m;
}

void freeMatrix(int **m, int rows) { delete[] m; }

int **transpose(int **m, int rows, int cols) {
  int **t = makeMatrix(rows, cols);
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      t[c][r] = m[r][c];
    }
  }
  return t;
}

void printMatrix(int **m, int rows, int cols) {
  for (int r = 0; r < cols; r++) {
    for (int c = 0; c < rows; c++) {
      std::cout << m[r][c] << (c + 1 < rows ? " " : "");
    }
    std::cout << std::endl;
  }
}
