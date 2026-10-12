// Collector of doubles: no duplicates allowed.
//
//   enter operation [a/r/q] and number: a 5.0
//   your numbers: 5
//   enter operation [a/r/q] and number: a 8.0
//   your numbers: 5 8
//   enter operation [a/r/q] and number: a 8.0
//   duplicate!
//   your numbers: 5 8
//   enter operation [a/r/q] and number: r 5.0
//   your numbers: 8
//   enter operation [a/r/q] and number: r 10.0
//   not present!
//   your numbers: 8
//   enter operation [a/r/q] and number: q

#include "list.hpp"
#include <iostream>

int main() {
  double *numbers = new double[0];
  int size = 0;
  char op;
  double value;

  std::cout << "enter operation [a/r/q] and number: ";
  while (std::cin >> op && op != 'q') {
    std::cin >> value;
    if (op == 'a') {
      if (check(numbers, value, size)) {
        std::cout << "duplicate!" << std::endl;
      } else {
        addNumber(numbers, value, size);
      }
    } else if (op == 'r') {
      if (!check(numbers, value, size)) {
        std::cout << "not present!" << std::endl;
      } else {
        removeNumber(numbers, value, size);
      }
    }
    std::cout << "your numbers: ";
    output(numbers, size);
    std::cout << "enter operation [a/r/q] and number: ";
  }

  delete[] numbers;
}
