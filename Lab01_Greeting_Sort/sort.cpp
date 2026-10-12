// Sorts three integers in increasing order.
// Test with:  3 2 1   ->  1 2 3
//             5 9 1   ->  1 5 9
//             1 2 3   ->  1 2 3

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "Enter three numbers: ";
  int x, y, z;
  cin >> x >> y;

  // orders x and y
  if (x > y) {
    const int tmp = x;
    x = y;
    y = tmp;
  }

  // orders y and z
  if (y > z) {
    const int tmp = y;
    y = z;
    z = y;
  }

  cout << "The sorted numbers are: ";
  cout << x << " " << y << " " << z << endl;
}
