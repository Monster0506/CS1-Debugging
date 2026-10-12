// Insertion sort and binary search on an int array.
//
// Expected output:
//   before: 9 4 7 1 8 2   sorted? no
//   after:  1 2 4 7 8 9   sorted? yes
//   search 7: index 3
//   search 5: index -1
//   search 1: index 0
//   search 9: index 5

#include <iostream>

void insertionSort(int a[], int n);
int binarySearch(const int a[], int n, int target); // index or -1
bool isSorted(const int a[], int n);
void print(const int a[], int n);

int main() {
  int data[] = {9, 4, 7, 1, 8, 2};
  const int N = 6;

  std::cout << "before: ";
  print(data, N);
  std::cout << "   sorted? " << (isSorted(data, N) ? "yes" : "no") << std::endl;

  insertionSort(data, N);
  std::cout << "after:  ";
  print(data, N);
  std::cout << "   sorted? " << (isSorted(data, N) ? "yes" : "no") << std::endl;

  int targets[] = {7, 5, 1, 9};
  for (int i = 0; i < 4; i++) {
    std::cout << "search " << targets[i] << ": index "
              << binarySearch(data, targets[i]) << std::endl;
  }
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j > 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int binarySearch(const int a[], int n, int target) {
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] == target) {
      return mid;
    } else if (a[mid] < target) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}

bool isSorted(const int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void print(const int a[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << (i + 1 < n ? " " : "");
  }
}
