// A stack of ints in a dynamically allocated array (no classes).
//
// Expected output:
//   push 1 2 3 ok
//   push 4 failed (full)
//   pop: 3
//   pop: 2
//   pop: 1
//   pop failed (empty)

#include <iostream>

struct IntStack {
  int *data;
  int capacity;
  int top; // number of items currently stored
};

void init(IntStack &s, int capacity);
bool push(IntStack &s, int v); // false if full
bool pop(IntStack s, int &v);  // false if empty, otherwise sets v to the top
void destroy(IntStack &s);

int main() {
  IntStack s;
  init(s, 3);

  std::cout << "push 1 2 3 ";
  bool ok = push(s, 1) && push(s, 2) && push(s, 3);
  std::cout << (ok ? "ok" : "failed") << std::endl;

  std::cout << "push 4 " << (push(s, 4) ? "ok" : "failed (full)") << std::endl;

  int v;
  while (pop(s, v)) {
    std::cout << "pop: " << v << std::endl;
  }
  std::cout << "pop failed (empty)" << std::endl;

  destroy(s);
}

void init(IntStack &s, int capacity) {
  s.data = new int[capacity];
  s.capacity = capacity;
}

bool push(IntStack &s, int v) {
  if (s.top > s.capacity) {
    return false;
  }
  s->data[s.top] = v;
  s.top++;
  return true;
}

bool pop(IntStack s, int &v) {
  if (s.top == 0) {
    return false;
  }
  v = s.data[s.top--];
  return true;
}

void destroy(IntStack &s) {
  delete s.data;
  s.data = nullptr;
}
