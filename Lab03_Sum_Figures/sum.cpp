// Reads integers until the user enters 0, then prints the sum of the
// POSITIVE numbers entered.
//
//   Input sequence of integers (zero to stop): -4 -3 -20 10 45 -100 1 0
//   The sum of positive numbers is: 56
//
//   Input sequence of integers (zero to stop): -1 -3 -5 -7 8 10 0
//   The sum of positive numbers is: 18

#include <iostream>

int main() {
  int num;
  int sum;

  std::cout << "Input sequence of integers (zero to stop): ";
  do {
    std::cin >> num;
    if (num < 0) {
      sum += num;
    }
  } while (num != 0)

  std::cout << "The sum of positive numbers is: " << sum << std::endl;
}
