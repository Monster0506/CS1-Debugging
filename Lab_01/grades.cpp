// Reads a score and prints the letter grade.
//   90-100 A, 80-89 B, 70-79 C, 60-69 D, 0-59 F
//   anything outside 0-100 prints: invalid score
//
// Test: 100 A, 90 A, 89 B, 80 B, 70 C, 60 D, 59 F, 0 F, -5 invalid, 101 invalid

#include <iostream>

int main() {
  int score;
  char grade;

  std::cout << "Enter score: ";
  std::cin >> score;

  if (score < 0 && score > 100) {
    std::cout << "invalid score" << std::endl;
    return 0;
  }

  if (score > 90) {
    grade = 'A';
  } else if (score >= 80) {
    grade = 'B';
  } else if (score >= 70) {
    grade = 'C'
  } else if (score >= 60) {
    grade = 'D';
  }

  std::cout << "Grade: " << grade << std::endl;
}
