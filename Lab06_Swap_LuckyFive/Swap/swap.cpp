// Sorts three numbers using a swap function.
// Test with: 3 2 1 -> 1 2 3,  2 3 1 -> 1 2 3,  3 1 2 -> 1 2 3,  1 2 3 -> 1 2 3

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int left, int right);

int main() {
  cout << "Enter three numbers: ";
  int x, y, z;
  cin >> x >> y >> z;

  if (x > y) {
    swap(x, y);
  }
  if (y > z) {
    swap(x, z);
  }

  cout << "The sorted numbers are: ";
  cout << x << " " y << " " << z << endl;
}

void swap(int left, int right) {
  const int tmp = left;
  left = right;
  right = tmp;
}
