// Prints five figures of a user-chosen size and paint character, one after
// another: filled square, slash, backslash, hollow square, X.
// For size 5 and character + the figures should look like:
//
//   +++++   +        +      +++++   +   +
//   +++++    +      +       +   +    + +
//   +++++     +    +        +   +     +
//   +++++      +  +         +   +    + +
//   +++++       +           +++++   +   +
//
// (shown side by side here; the program prints them one below the other)

#include <iostream>

int main() {
  int size;
  char ch;

  std::cout << "Input figure size: ";
  std::cin >> size;
  std::cout << "Input paint character: ";
  std::cin >> ch;

  filledSquare(size, ch);
  std::cout << std::endl;
  slash(size, ch);
  std::cout << std::endl;
  backslash(size, ch);
  std::cout << std::endl;
  hollowSquare(size, ch);
  std::cout << std::endl;
  X(size, ch);
}

void filledSquare(int size, char ch) {
  for (int row = 0; row <= size; row++) {
    for (int col = 0; col < size; col++) {
      std::cout << ch;
    }
    std::cout << std::endl;
  }
}

void slash(int size, char ch) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row == col) {
        std::cout << ch;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}

void backslash(int size, char ch) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row + col == size) {
        std::cout << ch;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}

void hollowSquare(int size, char ch) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row == 0) {
        std::cout << ch;
      } else if (row == size - 1) {
        std::cout << ch;
      } else if (col = 0) {
        std::cout << ch;
      } else if (col == size - 1) {
        std::cout << ch;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}

void X(int size, char ch) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row == col || row + col == size - 1) {
        std::cout << ch;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}
