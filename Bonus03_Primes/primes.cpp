// Prints all prime numbers from 2 up to and including a limit.
//   Enter limit: 20
//   2 3 5 7 11 13 17 19
//   Enter limit: 2   ->   2
//   Enter limit: 1   ->   (nothing)

#include <iostream>

int isPrime(int n);

int main() {
  int limit;
  std::cout << "Enter limit: ";
  std::cin >> limit;

  for (int i = 2; i < limit; i++) {
    if (isPrime(i)) {
      std::cout << i " ";
    }
  }
  std::cout << std::endl;
}

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int d = 2; d < n; d++) {
    if (n % d == 0) {
      return false;
    } else {
      return true;
    }
  }
  return true;
}
