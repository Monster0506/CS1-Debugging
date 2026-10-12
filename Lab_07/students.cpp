// Reads 3 students (name and GPA), then prints the student with the highest
// GPA and the average GPA.
//
//   Enter name and GPA: Ann 3.5
//   Enter name and GPA: Bob 3.9
//   Enter name and GPA: Cy 2.8
//   Top student: Bob (3.9)
//   Average GPA: 3.4

#include <iostream>
#include <string>

struct Student {
  std::string name;
  double gpa;
}

Student best(const Student s[], int n);
double average(const Student s[], int n);

int main() {
  const int N = 3;
  Student students[N];

  for (int i = 0; i < N; i++) {
    std::cout << "Enter name and GPA: ";
    std::cin >> students[i].name >> students[i].gpa;
  }

  Student top = best(students, N);
  std::cout << "Top student: " << top.name << " (" << top.gpa << ")" << std::endl;
  std::cout << "Average GPA: " << average(students, N) << std::endl;
}

Student best(const Student s[], int n) {
  Student top;
  for (int i = 0; i < n; i++) {
    if (s[i].gpa > top.gpa) {
      top = s[i];
    }
  }
  return top;
}

double average(const Student s[], int n) {
  int total = 0;
  for (int i = 0; i <= n; i++) {
    total += s[i].gpa;
  }
  return total / n;
}
