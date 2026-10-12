// Pointers and references.
//
// Expected output:
//   swap: 7 3
//   minmax: min=2 max=9
//   after doubling: 2 4 6 8
//   largest element is 9 at index 2

#include <iostream>

void swapInts(int *a, int *b);
void minMax(const int a[], int size, int &min, int &max);
void doubleAll(int a[], int size);
int *findLargest(int a[], int size);

int main() {
  int x = 3, y = 7;
  swapInts(x, y);
  std::cout << "swap: " << x << " " << y << std::endl;

  int data[] = {5, 2, 9, 4};
  int lo, hi;
  minMax(data, 4, lo, hi);
  std::cout << "minmax: min=" << lo << " max=" << hi << std::endl;

  int small[] = {1, 2, 3, 4};
  doubleAll(small, 4);
  std::cout << "after doubling:";
  for (int i = 0; i < 4; i++) {
    std::cout << " " << small[i];
  }
  std::cout << std::endl;

  int *big = findLargest(data, 4);
  std::cout << "largest element is " << *big << " at index " << (big - data)
            << std::endl;
}

void swapInts(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

void minMax(const int a[], int size, int &min, int &max) {
  min = 0;
  max = 0;
  for (int i = 1; i < size; i++) {
    if (a[i] < min) {
      min = a[i];
    }
    if (a[i] > max) {
      max = a[i];
    }
  }
}

void doubleAll(int a[], int size) {
  for (int i = 0; i < size; i++) {
    a[i] * 2;
  }
}

int *findLargest(int a[], int size) {
  int largest = a[0];
  for (int i = 1; i < size; i++) {
    if (a[i] > largest) {
      largest = a[i];
    }
  }
  return &largest;
}
