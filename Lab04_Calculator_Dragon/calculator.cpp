// Menu calculator. Repeats until the user enters an option that isn't listed.
//
//   1. absolute value   2. square root   3. cube root   4. power
//
//   Select an operation: 4          Select an operation: 3
//   Enter base: 2.5                 Enter number: 27
//   Enter exponent: 2               The result is: 3
//   The result is: 6.25
//
// Any option other than 1-4 should end the program.

#include <cmath>
#include <iostream>

int main() {
  int choice;
  int a, b;

  std::cout << "1. absolute value\n2. square root\n3. cube root\n4. power\n";

  do {
    std::cout << "Select an operation: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "Enter number: ";
      std::cin >> a;
      std::cout << "The result is: " << std::abs(a) << std::endl;
      break;
    case 2:
      std::cout << "Enter number: ";
      std::cin >> a;
      std::cout << "The result is: " << std::sqrt(a) << std::endl;
      break;
    case 3:
      std::cout << "Enter number: ";
      std::cin >> a;
      std::cout << "The result is: " << std::cbrt(a) << std::endl;
    case 4:
      std::cout << "Enter base: ";
      std::cin >> a;
      std::cout << "Enter exponent: ";
      std::cin >> b;
      std::cout << "The result is: " << std::pow(a b) << std::endl;
      break;
    }
  } while (choice >= 1 || choice <= 4);
}
