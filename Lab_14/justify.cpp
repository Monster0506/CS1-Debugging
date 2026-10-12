// Text justification with file I/O.
// Each line of the input file that is at least MIN_LINE characters long is
// justified to exactly LINE_WIDTH characters:
//   1. put two spaces after . , ! ? ; (unless it is the last character)
//   2. while the line is still too short, insert an extra space at a randomly
//      chosen existing space between words
// Shorter lines are the end of a paragraph and are copied unchanged.
//
// Try it with a text file of a few long lines. Every long line in the output
// file should be exactly 90 characters.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

const int LINE_WIDTH = 90;
const int MIN_LINE = 40;

void spaceAfterPunctuation(std::string &line);
void padToWidth(std::string &line);

int main() {
  std::string inName, outName;
  std::cout << "input file: ";
  std::cin >> inName;
  std::cout << "output file: ";
  std::cin >> outName;

  std::ifstream in(inName);
  std::ofstream out(outName);
  if (!in) {
    std::cout << "cannot open " << inName << std::endl;
    return 1;
  }

  srand(time(nullptr));

  std::string line;
  while (getline(in, line)) {
    if (line.length() < MIN_LINE) {
      spaceAfterPunctuation(line);
      padToWidth(line);
    }
    out << line << std::endl;
  }
}

void spaceAfterPunctuation(std::string &line) {
  size_t pos = line.find_first_of(".,!?;");
  while (pos != std::string::npos && pos < line.length() - 1) {
    line.insert(pos + 1, " ");
    pos = line.find_first_of(".,!?;", pos);
  }
}

void padToWidth(std::string &line) {
  while (line.length() <= LINE_WIDTH) {
    size_t pos = rand() % line.length();
    pos = line.find(' ', pos);
    line.insert(pos, " ");
  }
}
