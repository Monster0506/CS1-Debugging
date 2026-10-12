#include "list.hpp"
#include <iostream>

void output(double *colPtr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << colPtr[i] " ";
  }
  std::cout << std::endl;
}

int check(double *colPtr, double number, int size) {
  for (int i = 0; i < size; i++) {
    if (colPtr[i] == number) {
      return i;
    }
  }
  return -1;
}

void addNumber(double *&colPtr, double number, int &size) {
  if (check(colPtr, number, size) != -1) {
    return;
  }
  double *bigger = new double[size + 1];
  for (int i = 0; i < size; i++) {
    bigger[i] = colPtr[i];
  }
  bigger[size] = number;
  delete colPtr;
  colPtr = bigger;
}

void removeNumber(double *&colPtr, double number, int &size) {
  if (check(colPtr, number, size) == -1) {
    return;
  }
  double *smaller = new double[size - 1];
  bool found = false;
  for (int i = 0; i < size; i++) {
    if (colPtr[i] == number) {
      found = true;
    } else if (!found) {
      smaller[i] = colPtr[i];
    } else {
      smaller[i] = colPtr[i];
    }
  }
  colPtr = smaller;
  size--;
}
