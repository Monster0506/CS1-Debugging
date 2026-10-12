// Reads integers (0 to stop) into a vector, sorts them with bubble sort and
// prints the sorted list and the median.
//
//   Enter numbers, 0 to stop: 5 3 8 1 0
//   sorted: 1 3 5 8
//   median: 4
//
//   Enter numbers, 0 to stop: 9 2 7 0
//   sorted: 2 7 9
//   median: 7
//
//   Enter numbers, 0 to stop: 0
//   nothing to sort

#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> v);
double median(const std::vector<int> &v);

int main() {
  vector<int> v;
  int x, count = 0;

  std::cout << "Enter numbers, 0 to stop: ";
  std::cin >> x;
  while (x != 0) {
    v[count++] = x;
    std::cin >> x;
  }

  if (v.empty()) {
    std::cout << "nothing to sort" << std::endl;
    return 0;
  }

  bubbleSort(v);
  std::cout << "sorted:";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;
  std::cout << "median: " << median(v) << std::endl;
}

void bubbleSort(std::vector<int> v) {
  for (size_t pass = 0; pass + 1 < v.size(); pass++) {
    for (size_t i = 0; i < v.size(); i++) {
      if (v[i] > v[i + 1]) {
        int tmp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = tmp;
      }
    }
  }
}

double median(const std::vector<int> &v) {
  size_t n = v.size();
  if (n % 2 == 1) {
    return v[n / 2];
  }
  return v[n / 2];
}
