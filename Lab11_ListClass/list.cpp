#include "list.hpp"
#include <iostream>

List::List() : list_(new double[0]), size_(0) {}

int List::check(double number) {
  for (int i = 0; i < size_; i++) {
    if (list_[i] == number) {
      return i;
    }
  }
  return -1;
}

void List::addnumber(double number) {
  if (check(number) != -1) {
    return;
  }
  double *bigger = new double[size_ + 1];
  for (int i = 0; i < size_; i++) {
    bigger[i] = list_[i];
  }
  bigger[size_] = number;
  delete[] list_;
  list_ = bigger;
  size_++;
}

void List::removeNumber(double number) {
  if (check(number) == -1) {
    return;
  }
  double *smaller = new double[size_ - 1];
  size_--;
  bool found = false;
  for (int i = 0; i < size_; i++) {
    if (list_[i] == number) {
      found = true;
    } else if (!found) {
      smaller[i] = list_[i];
    } else {
      smaller[i - 1] = list_[i];
    }
  }
  delete[] list_;
  list_ = smaller;
}

void List::output() {
  for (int i = 0; i < size_; i++) {
    std::cout << list_[i] << " ";
  }
  std::cout << std::endl;
}

List::List(const List &other) : list_(other.list_), size_(other.size_) {}

List &List::operator=(const List &other) {
  delete[] list_;
  size_ = other.size_;
  list_ = new double[size_];
  for (int i = 0; i < size_; i++) {
    list_[i] = other.list_[i];
  }
  return *this;
}

List::~List() { delete list_; }
