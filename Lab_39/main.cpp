// Tests the three sorting functions from sort_lib.
// Expected output:
//   quick:     -3 0 1 2 5 5 6 9
//   selection: -3 0 1 2 5 5 6 9
//   bubble:    -3 0 1 2 5 5 6 9
//   empty and one-element vectors are fine

#include "sort_lib.h"
#include <iostream>
#include <vector>

static void show(const char *name, const std::vector<int> &v) {
    std::cout << name;
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << (i ? " " : "") << v[i];
    }
    std::cout << std::endl;
}

int main() {
    const int raw[] = {5, 2, 9, 1, 5, 6, 0, -3};
    std::vector<int> a(raw, raw + 8), b = a, c = a;

    quick_sort(a);
    show("quick:     ", a);
    selection_sort(b);
    show("selection: ", b);
    bubble_sort(c);
    show("bubble:    ", c);

    std::vector<int> empty, one(1, 42);
    quick_sort(empty);
    selection_sort(empty);
    bubble_sort(empty);
    quick_sort(one);
    selection_sort(one);
    bubble_sort(one);
    std::cout << "empty and one-element vectors are fine" << std::endl;
}
