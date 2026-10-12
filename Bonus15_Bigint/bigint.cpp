// Big numbers stored in an int array, one digit per element, least
// significant digit at index 0:   1234  ->  {4, 3, 2, 1, 0, 0, ...}
//
// Expected output:
//   299793 + 1207 = 301000
//   999 + 1 = 1000
//   299793 * 10 = 2997930
//   0 + 0 = 0

#include <iostream>

const int CAPACITY = 20;

void fromString(const char *text, int digits[]);
void printBig(const int digits[]); // no leading zeros; prints 0 for zero
void add(const int a[], const int b[], int result[]);
void timesTen(int digits[]);

int main() {
  int a[CAPACITY], b[CAPACITY], sum[CAPACITY];

  fromString("299793", a);
  fromString("1207", b);
  add(a, b, sum);
  std::cout << "299793 + 1207 = ";
  printBig(sum);

  fromString("999", a);
  fromString("1", b);
  add(a, b, sum);
  std::cout << "999 + 1 = ";
  printBig(sum);

  fromString("299793", a);
  timesTen(a);
  std::cout << "299793 * 10 = ";
  printBig(a);

  fromString("0", a);
  fromString("0", b);
  add(a, b, sum);
  std::cout << "0 + 0 = ";
  printBig(sum);
}

void fromString(const char *text, int digits[]) {
  int len = 0;
  while (text[len] != '\0') {
    len++;
  }
  for (int i = 0; i < len; i++) {
    digits[i] = text[len - 1 - i];
  }
}

void printBig(const int digits[]) {
  int top = CAPACITY - 1;
  while (top > 0 && digits[top] == 0) {
    top--;
  }
  for (int i = 0; i <= top; i++) {
    std::cout << digits[i];
  }
  std::cout << std::endl;
}

void add(const int a[], const int b[], int result[]) {
  int carry = 0;
  for (int i = 0; i < CAPACITY; i++) {
    int sum = a[i] + b[i] + carry;
    result[i] = sum;
    carry = sum / 10;
  }
}

void timesTen(int digits[]) {
  for (int i = CAPACITY; i > 0; i--) {
    digits[i] = digits[i - 1];
  }
  digits[0] = 0;
}
