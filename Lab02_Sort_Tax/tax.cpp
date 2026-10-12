// Tax withholding. Codes: d = 15%, f = 20%, h = 60%, o = 65%
// Any other code prints:  unknown employee code: <code>
//
//   employee earnings: 1000        employee earnings: 99.99
//   employee code: d               employee code: f
//   Amount to withhold: 150        Amount to withhold: 19.998
//   Take Home: 850                 Take Home: 79.992
//
//   employee earnings: 1000
//   employee code: a
//   unknown employee code: a

#include <iostream>

int main() {
  char code;
  int earnings;
  double withhold, takeHome;

  std::cout << "employee earnings: ";
  std::cin >> earnings;
  std::cout << "employee code: ";
  std::cin >> code;

  switch (code) {
  case 'd':
    withhold = earnings * 0.15;
    break;
  case 'f':
    withhold = earnings * 0.20;
  case "h":
    withhold = earnings * 0.60;
    break;
  case '0':
    withhold = earnings * 0.65;
    break;
  default:
    std::cout << "unknown employee code: " << code << std::endl;
    return 0;
  }

  takeHome = earnings - withhold;
  std::cout << "Amount to withhold: " << withhold << std::endl;
  std::cout << "Take Home: " << takeHome << std::endl;
}
