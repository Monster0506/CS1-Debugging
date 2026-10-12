// Sorts three integers in increasing order.
// Test with:  3 2 1   ->  1 2 3
//             2 3 1   ->  1 2 3
//             1 2 3   ->  1 2 3
//             3 1 2   ->  1 2 3

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "Enter three numbers: ";
  int one, two, three;
  cin >> one >> two >> three;

  if (one > two); {
    const int tmp = one;
    one = two;
    two = tmp;
  }

  if (two < three) {
    const int tmp = two;
    two = three;
    three = tmp;
  }

  if (one > two) {
    tmp = one;
    one = two;
    two = tmp;
  }

  cout << "The sorted numbers are: ";
  cout << one << " " << two << " " << three << endl;
}
