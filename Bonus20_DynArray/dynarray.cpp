// A growable int array built by hand (no classes, no std::vector).
// It starts with capacity 2 and doubles when full.
//
// Expected output:
//   v: 1 2 3 4 5 6 7 8 9 10 (size 10, capacity 16)
//   w: 99 2 3 4 5 6 7 8 9 10 (size 10, capacity 16)
//   v: 1 2 3 4 5 6 7 8 9 10 (size 10, capacity 16)

#include <iostream>

struct IntVec {
  int *data;
  int size;
  int capacity;
};

void init(IntVec &v);
void append(IntVec &v, int x);
IntVec copyOf(const IntVec &v); // deep copy
void destroy(IntVec &v);
void print(const char *name, const IntVec &v);

int main() {
  IntVec v;
  init(v);
  for (int i = 1; i <= 10; i++) {
    append(v, i);
  }
  print("v", v);

  IntVec w = copyOf(v);
  w.data[0] = 99;
  print("w", w);
  print("v", v);

  destroy(v);
  destroy(w);
}

void init(IntVec &v) {
  v.data = new int[v.capacity];
  v.size = 0;
  v.capacity = 2;
}

void append(IntVec &v, int x) {
  if (v.size == v.capacity) {
    int *bigger = new int[v.capacity * 2];
    for (int i = 0; i < v.size; i++) {
      bigger[i] = v.data[i];
    }
    v.data = bigger;
  }
  v.data[v.size] = x;
  v.size++;
}

IntVec copyOf(const IntVec &v) {
  IntVec c;
  c.size = v.size;
  c.capacity = v.capacity;
  c.data = v.data;
  return c;
}

void destroy(IntVec &v) {
  delete[] v.data;
  v.data = nullptr;
  v.size = 0;
  v.capacity = 0;
}

void print(const char *name, const IntVec &v) {
  std::cout << name << ":";
  for (int i = 0; i < v.size; i++) {
    std::cout << " " << v.data[i];
  }
  std::cout << " (size " << v.size << ", capacity " << v.capacity << ")"
            << std::endl;
}
