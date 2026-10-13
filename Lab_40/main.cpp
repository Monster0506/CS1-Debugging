// Tests the linked-list stack template and uses it to convert a fully
// parenthesized infix expression to postfix and prefix.
//
// Expected output:
//   top: 3
//   copy top: 3
//   popped: 3 2 1
//   copy still has: 3 2 1
//   assigned top: 3
//   postfix: A B C * + D E - /
//   prefix:  / + A * B C - D E

#include "stack.hpp"
#include <iostream>
#include <sstream>
#include <string>

// for each token: ")" pops rhs, op, lhs and pushes the combined expression,
// anything except "(" is pushed
std::string convert(const std::string &expr, bool prefix) {
    stack<std::string> S;
    std::istringstream in(expr);
    std::string t;
    while (in >> t) {
        if (t == ")") {
            std::string lhs = S.pop();
            std::string op = S.pop();
            std::string rhs = S.pop();
            if (prefix) {
                S.push(op + " " + lhs + " " + rhs);
            } else {
                S.push(lhs + " " + rhs + " " + op);
            }
        } else if (t != "(") {
            S.push(t);
        }
    }
    return S.pop();
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "top: " << s.top() << std::endl;

    stack<int> copy(s);
    std::cout << "copy top: " << copy.top() << std::endl;

    std::cout << "popped:";
    while (!s.empty()) {
        std::cout << " " << s.pop();
    }
    std::cout << std::endl;

    stack<int> temp = copy;
    std::cout << "copy still has:";
    while (!copy.empty()) {
        std::cout << " " << copy.pop();
    }
    std::cout << std::endl;

    stack<int> assigned;
    assigned = temp;
    std::cout << "assigned top: " << assigned.top() << std::endl;

    const std::string expr = "( ( A + ( B * C ) ) / ( D - E ) )";
    std::cout << "postfix: " << convert(expr, false) << std::endl;
    std::cout << "prefix:  " << convert(expr, true) << std::endl;
}
