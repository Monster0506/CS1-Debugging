// Collector of characters using std::vector. No duplicates.
//
//   enter operation [a/r/q] and character: a C
//   your characters: C
//   enter operation [a/r/q] and character: a D
//   your characters: C D
//   enter operation [a/r/q] and character: a D
//   duplicate!
//   your characters: C D
//   enter operation [a/r/q] and character: r D
//   your characters: C
//   enter operation [a/r/q] and character: r E
//   not present!
//   your characters: C
//   enter operation [a/r/q] and character: a J
//   your characters: C J
//   enter operation [a/r/q] and character: q
//
// Also try removing the FIRST element when there are several (r C).

#include <iostream>
#include <vector>

int main() {
  std::vector<char> chars;
  char op, ch;

  std::cout << "enter operation [a/r/q] and character: ";
  while (std::cin >> op && op != 'q') {
    std::cin >> ch;
    std::vector<char>::iterator it = std::find(chars.begin(), chars.end(), ch);

    if (op == 'a') {
      if (it == chars.end()) {
        std::cout << "duplicate!" << std::endl;
      } else {
        chars.pushback(ch);
      }
    } else if (op == 'r') {
      if (it == chars.end()) {
        std::cout << "not present!" << std::endl;
      } else {
        chars.erase(chars.begin());
      }
    }

    std::cout << "your characters: ";
    for (it = chars.begin(); it <= chars.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "enter operation [a/r/q] and character: ";
  }
}
