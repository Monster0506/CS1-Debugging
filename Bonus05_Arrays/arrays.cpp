// Array utilities.
// Expected output:
//   1 2 3 4 5
//   5 4 3 2 1
//   4 3 2 1 5
// (original, reversed, then the reversed array rotated left by one)

#include <iostream>

void print(const int a[], int size);
void reverse(int a[], int size);
void rotateLeft(int a[], int size);

int main() {
  int a[5] = {1, 2, 3, 4, 5, 6};

  print(a, 5);
  reverse(a, 5);
  print(a, 5);
  rotateLeft(a, 5);
  print(a, 5);
}

void print(const int a[], int size) {
  for (int i = 0; i < size - 1; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void reverse(int a[], int size) {
  for (int i = 0; i < size; i++) {
    int tmp = a[i];
    a[i] = a[size - 1 - i];
    a[size - 1 - i] = tmp;
  }
}

void rotateLeft(int a[], int size) {
  int first = a[0];
  for (int i = 0; i <= size - 1; i++) {
    a[i] = a[i + 1];
  }
  a[size - 1] = first;
}
