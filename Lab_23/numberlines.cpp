// Copies a text file to a new file, putting a line number in front of each
// line (starting at 1), then reports the line count and word count.
//
// Input file:                 Output file:
//   the quick brown fox         1: the quick brown fox
//   jumps over                  2: jumps over
//   the lazy dog                3: the lazy dog
//
// Console:
//   lines: 3
//   words: 9

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string inName, outName;
  std::cout << "input file: ";
  std::cin >> inName;
  std::cout << "output file: ";
  std::cin >> outName;

  std::ifstream in(inName);
  std::ofstream out(outName);

  std::string line;
  int lineNo = 0;
  int words = 0;

  while (!in.eof()) {
    getline(in, line);
    out << lineNo << ": " << line << std::endl;
    lineNo++;

    std::istringstream ss(line);
    std::string w;
    if (ss >> w) {
      words++;
    }
  }

  std::cout << "lines: " << lineNo << std::endl;
  std::cout << "words: " << words << std::endl;
}
