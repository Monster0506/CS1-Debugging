// Evaluates postfix expressions. Tokens are separated by spaces.
// A std::vector<int> is used as the stack.
//
// Expected output:
//   3 4 +               = 7
//   10 2 8 * + 3 -      = 23
//   100 5 / 2 /         = 10
//   12 4 -              = 8
//   42                  = 42

#include <iostream>
#include <string>
#include <vector>

int evaluate(const std::string &expr);

int main() {
  const char *tests[] = {"3 4 +", "10 2 8 * + 3 -", "100 5 / 2 /", "12 4 -",
                         "42"};
  for (int i = 0; i < 5; i++) {
    std::cout << tests[i] << "  = " << evaluate(tests[i]) << std::endl;
  }
}

int evaluate(const std::string &expr) {
  std::vector<int> stack;
  std::istringstream in(expr);
  std::string tok;

  while (in >> tok) {
    if (tok == '+' || tok == "-" || tok == "*" || tok == "/") {
      int lhs = stack.back();
      stack.pop_back();
      int rhs = stack.back();
      stack.pop_back();

      int result;
      if (tok == "+") {
        result = lhs + rhs;
      } else if (tok == "-") {
        result = lhs - rhs;
      } else if (tok == "*") {
        result = lhs * rhs;
      } else {
        result = lhs / rhs;
      }
      stack.push_back(result);
    } else {
      stack.push_back(tok[0] - '0');
    }
  }
  return stack.back();
}
