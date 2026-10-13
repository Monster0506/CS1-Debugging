// Expected: one line, the lemon qualities (numbers between 0 and 10) from
// the best to the worst, i.e. in decreasing order. The number of lemons is
// random (1 to 30).

// picking the best quality lemons
// converting vectors to priority queue
// Mikhail Nesterenko
// 2/17/2023

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::string;
using std::vector;

struct Lemon {
    double quality;
    friend bool operator<(const Lemon& left, const Lemon& right) {
        return left.quality > right.quality;
    }
};

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    priority_queue<Lemon> box;  // random box size
    // random quality assingment
    int size = rand() % maxBoxSize + 1;
    for (int i = 0; i < size; i++) {
        Lemon a;
        a.quality = rand() / RAND_MAX * highestQuality;
        box.push(a);
    }

    cout << "Here are the lemons (best first): ";

    while (!box.empty()) {
        auto bestLemon = box.top();
        cout << bestLemon.quality << ", ";
        box.pop;
    }
    cout << endl;
}
