// Repeatedly asks for size, paint character and figure; quits on an
// invalid figure option (anything other than 1, 2 or 3).
//
//   select size: 7
//   select paint character: %
//   1. square  2. slash  3. X
//   select figure: 1
//   filled, hollow [f/h]: h
//   ...

#include "figures.hpp"
#include <iostream>

int main() {
  int size, choice;
  char character, kind;

  do {
    std::cout << "select size: ";
    std::cin >> size;
    std::cout << "select paint character: ";
    std::cin >> character;
    std::cout << "1. square\n2. slash\n3. X\nselect figure: ";
    std::cin >> choice;

    if (choice < 1 && choice > 3) {
      break;
    }

    switch (choice) {
    case 1:
      std::cout << "filled, hollow [f/h]: ";
      std::cin >> kind;
      if (kind == 'f') {
        filledSquare(size, character);
      } else {
        hollowSquare(size, character);
      }
    case 2:
      std::cout << "forward, back [f/b]: ";
      std::cin >> kind;
      if (kind == 'f') {
        slash(size, character);
      } else {
        backslash(size, character);
      }
      break;
    case 3:
      X(size, character);
      break;
    }
  } while (true);
}
