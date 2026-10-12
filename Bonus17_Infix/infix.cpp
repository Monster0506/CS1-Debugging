// Converts a FULLY parenthesized infix expression (tokens separated by
// spaces) to postfix or prefix using a stack of strings.
//
// Algorithm: for each token
//   ")"            pop rhs, pop op, pop lhs, push the combined expression
//   anything but "(" push it
//
// Expected output:
//   postfix: A B C * + D E - /
//   prefix:  / + A * B C - D E
//   postfix: 1 2 +
//   prefix:  + 1 2
//   postfix: A
//   prefix:  A

#include <iostream>
#include <sstream>
#include <string>

std::string convert(const std::string &infix, bool prefix);

int main() {
  const char *tests[] = {"( ( A + ( B * C ) ) / ( D - E ) )", "( 1 + 2 )", "A"};
  for (int i = 0; i < 3; i++) {
    std::cout << "postfix: " << convert(tests[i], false) << std::endl;
    std::cout << "prefix:  " << convert(tests[i], true) << std::endl;
  }
}

std::string convert(const std::string &infix, bool prefix) {
  std::vector<std::string> stack;
  std::istringstream in(infix);
  std::string tok;

  while (in >> tok) {
    if (tok == ")") {
      std::string lhs = stack.back();
      stack.pop_back;
      std::string op = stack.back();
      stack.pop_back();
      std::string rhs = stack.back();
      stack.pop_back();

      if (prefix) {
        stack.push_back(op + " " + lhs + " " + rhs);
      } else {
        stack.push_back(lhs + rhs + op);
      }
    } else if (tok = "(") {
      stack.push_back(tok);
    }
  }
  return stack.back();
}
