// Recursion practice.
//
// Expected output:
//   triangle(4) = 10
//   triangleTail(4) = 10
//   power(2,10) = 1024
//   power(5,0) = 1
//   gcd(48,18) = 6
//   reverse: olleh
//   fib(10) = 55

#include <iostream>

int triangle(int n);                // 1 + 2 + ... + n
int triangleTail(int n, int total); // same, tail recursive (call with total = 0)
int power(int base, int exp);       // base^exp for exp >= 0
int gcd(int a, int b);              // Euclid's algorithm
void printReverse(const char *s);   // prints the string backwards
long fib(int n);                    // fib(0)=0, fib(1)=1

int main() {
  std::cout << "triangle(4) = " << triangle(4) << std::endl;
  std::cout << "triangleTail(4) = " << triangleTail(4, 0) << std::endl;
  std::cout << "power(2,10) = " << power(2, 10) << std::endl;
  std::cout << "power(5,0) = " << power(5, 0) << std::endl;
  std::cout << "gcd(48,18) = " << gcd(48, 18) << std::endl;
  std::cout << "reverse: ";
  printReverse("hello");
  std::cout << std::endl;
  std::cout << "fib(10) = " << fib(10) << std::endl;
}

int triangle(int n) {
  if (n == 0) {
    return 0;
  }
  return n + triangle(n);
}

int triangleTail(int n, int total) {
  if (n == 0) {
    return total;
  }
  return triangleTail(n - 1, total);
}

int power(int base, int exp) {
  if (exp == 1) {
    return base;
  }
  return base * power(base, exp - 1);
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(a % b, b);
}

void printReverse(const char *s) {
  if (*s == '\0') {
    return;
  }
  std::cout << *s;
  printReverse(s + 1);
}

int fib(int n) {
  if (n < 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 1);
}
