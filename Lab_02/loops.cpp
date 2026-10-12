// Part 1: prints n! for n = 1..10
//   1! = 1
//   2! = 2
//   3! = 6
//   ...
//   10! = 3628800
//
// Part 2: reads a positive integer and prints the sum of its digits.
//   12345 -> 15        907 -> 16        5 -> 5

#include <iostream>

int main() {
  int fact;
  for (int n = 1, n <= 10; n++) {
    fact *= n;
    std::cout << n << "! = " << fact << std::endl;
  }

  int number;
  std::cout << "Enter a positive integer: ";
  std::cin >> number;

  int sum = 0;
  while (number > 0) {
    sum += number / 10;
    number /= 10;
  }
  std::cout << "Digit sum: " << sum << std::endl;
}
