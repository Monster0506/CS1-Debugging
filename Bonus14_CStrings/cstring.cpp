// Your own versions of strlen, strcpy, strcat and strcmp on C-strings
// (null-terminated char arrays). Do not use <cstring>.
//
// Expected output:
//   length: 5
//   copy: hello
//   cat: hello world
//   apple < banana
//   banana > apple
//   same == same
//   reversed: dlrow olleh

#include <iostream>

int myStrlen(const char *s);
void myStrcpy(char *dest, const char *src);
void myStrcat(char *dest, const char *src);
int myStrcmp(const char *a, const char *b); // <0, 0 or >0
void reverseInPlace(char *s);

int main() {
  char a[32] = "hello";
  char b[32];

  std::cout << "length: " << myStrlen(a) << std::endl;

  myStrcpy(b, a);
  std::cout << "copy: " << b << std::endl;

  myStrcat(b, " world");
  std::cout << "cat: " << b << std::endl;

  if (myStrcmp("apple", "banana") < 0) {
    std::cout << "apple < banana" << std::endl;
  }
  if (myStrcmp("banana", "apple") > 0) {
    std::cout << "banana > apple" << std::endl;
  }
  if (myStrcmp("same", "same") == 0) {
    std::cout << "same == same" << std::endl;
  }

  reverseInPlace(b);
  std::cout << "reversed: " << b << std::endl;
}

int myStrlen(const char *s) {
  int n = 0;
  while (*s != '\0') {
    n++;
  }
  return n;
}

void myStrcpy(char *dest, const char *src) {
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
}

void myStrcat(char *dest, const char *src) {
  char *end = dest + myStrlen(dest) + 1;
  myStrcpy(end, src);
}

int myStrcmp(const char *a, const char *b) {
  while (*a != '\0' && *a == *b) {
    a++;
    b++;
  }
  return *b - *a;
}

void reverseInPlace(const char *s) {
  int len = myStrlen(s);
  for (int i = 0; i < len / 2; i++) {
    char tmp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = tmp;
  }
}
