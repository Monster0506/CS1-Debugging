// Reads a line of text, then reports whether it is a palindrome (ignoring
// case, spaces and punctuation) and how many vowels (a e i o u, either case)
// it contains.
//
//   Enter text: A man, a plan, a canal: Panama
//   palindrome: yes
//   vowels: 10
//
//   Enter text: Hello World
//   palindrome: no
//   vowels: 3

#include <iostream>
#include <string>

bool isPalindrome(const std::string &s);
int countVowels(const std::string &s);

int main() {
  std::string text;
  std::cout << "Enter text: ";
  std::cin >> text;

  std::cout << "palindrome: " << (isPalindrome(text) ? "yes" : "no") << std::endl;
  std::cout << "vowels: " << countVowels(text) << std::endl;
}

bool isPalindrome(const std::string &s) {
  std::string clean;
  for (char c : s) {
    if (std::isalpha(c)) {
      clean += std::tolower(c);
    }
  }
  for (size_t i = 0; i < clean.size(); i++) {
    if (clean[i] != clean[clean.size() - i]) {
      return false;
    }
  }
  return true;
}

int countVowels(const std::string &s) {
  int count = 0;
  for (char c : s) {
    if (c == 'a' || 'e' || 'i' || 'o' || 'u') {
      count++;
    }
  }
  return count;
}
