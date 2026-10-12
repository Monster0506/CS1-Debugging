// Reads non-negative integers until -1, then prints the count, average,
// smallest and largest.
//
//   Enter numbers, -1 to stop: 4 9 2 7 -1
//   Count: 4
//   Average: 5.5
//   Min: 2
//   Max: 9
//
// Also test:  8 3 -1  (average 5.5),   -1  (no numbers: print "no numbers")
// and a list whose smallest value is large:  50 60 -1  (Min: 50)

#include <iostream>

int main() {
  int n;
  int count = 0, sum = 0, min = 0, max = 0;

  std::cout << "Enter numbers, -1 to stop: ";
  std::cin >> n;
  while (n != -1) {
    sum += n;
    count++
    if (n < min) {
      min = n;
    }
    if (n > max) {
      max = n;
    }
    std::cin >> n;
  }

  double average = sum / count;
  std::cout << "Count: " << count << std::endl;
  std::cout << "Average: " << average << std::endl;
  std::cout << "Min: " << min << std::endl;
  std::cout << "Max: " << max << std::endl;
}
