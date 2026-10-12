// Expected output:
//   a: 1.5 2.5 3.5
//   a: 1.5 2.5 3.5      (b is an independent copy)
//   b: 2.5 3.5
//   b: 2.5 3.5          (c is an independent copy)
//   c: 2.5 3.5 9
//   c: 2.5 3.5 9        (self-assignment must be harmless)

#include "list.hpp"
#include <iostream>

int main() {
  List a;
  a.addNumber(1.5);
  a.addNumber(2.5);
  a.addNumber(2.5);
  a.addNumber(3.5);
  std::cout << "a: ";
  a.output();

  List b(a);
  b.removeNumber(1.5);
  std::cout << "a: ";
  a.output();
  std::cout << "b: ";
  b.output();

  List c;
  c = b;
  c.addNumber(9);
  std::cout << "b: ";
  b.output();
  std::cout << "c: ";
  c.output();

  c = c;
  std::cout << "c: ";
  c.output();
}
