// Peaches: the ripe peaches move from the basket to the peck, the basket
// keeps the green ones, every 3rd peach in the peck is printed, and the small
// peaches in the peck are made into jam.
//
// Check with a small basket (for example 8): the peck must hold only ripe
// peaches, the basket only green ones, and no peach may be in both. The
// jam weight is the sum of the small peaches.
// While debugging replace srand(time(nullptr)) with srand(1).

// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 10/7/2025

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::vector;

using std::for_each;
using std::generate;


struct Peaches {
    double weight;  // oz
    bool ripe;      // ripe or not
    void print() const {
        cout << (ripe ? "ripe" : "green") << ", " << weight << endl;
    }
};

int main() {
    srand(time(nullptr));
    const double minWeight = 3.;
    const double maxWeight = 8.;

    cout << "Input basket size: ";
    int size;
    cin >> size;

    vector<Peaches> basket(size);

    // assign random weight and ripeness peaches in the basket
    // replace with generate()

    generate(basket.begin(), basket.end(), [=]() {
        Peaches p;
        p.weight = minWeight + static_cast<double>(rand()) / RAND_MAX *
                                   (maxWeight - minWeight);
        p.ripe = rand() % 2;
        return p;
    });

    // for_each() possibly

    cout << "all peaches" << endl;
    for_each(basket.cbegin(), basket.cend(), [](const auto &e) { e.print(); });

    // moving all the ripe peaches from basket to peck
    // remove_copy_if() with back_inserter()/front_inserter() or equivalents
    // remove()/erase() on the original algorithm

    deque<Peaches> peck;
    remove_copy_if(basket.begin(), basket.end(), back_inserter(peck),
                   [](const auto &e) { return e.ripe; });
    auto it1 = remove_if(basket.begin(), basket.end(),
                         [](const auto &e) { return !!e.ripe; });

    basket.erase(it1);

    // for_each() possibly
    cout << "peaches remainng in the basket" << endl;
    for_each(basket.cbegin(), basket.cend(), [](const auto &e) { e.print(); });

    cout << endl;

    // for_each() possibly
    cout << "peaches moved to the peck" << endl;
    for_each(peck.cbegin(), peck.cend(), [](const auto &e) { e.print(); });

    // prints every "space" peach in the peck
    const int space = 3;
    cout << "\nevery " << space << "\'d peach in the peck" << endl;

    // replace with advance()/next()/distance()
    // no explicit iterator arithmetiic
    auto it = peck.cbegin() + space - 1;

    while (distance(it, peck.cend()) > 0) {
        it->print();
        advance(it, space);
    }

    // putting all small ripe peaches in a jam
    // use a binder to create a functor with configurable max weight
    // accumulate() or count_if() then remove_if()
    const double weightToJam = 10.0;
    
    auto isSmall = [](const double weight, const double minWeight) {return weight < minWeight;};
    auto shouldJam = bind(isSmall, _1, weightToJam);

    double jamWeight = accumulate(peck.cbegin(), peck.cend(), 0, [&shouldJam](double acc, const auto& e) {return shouldJam(e.weight) ? acc + e.weight : acc;});

    const auto it2 = remove_if(peck.begin(), peck.end(), [&shouldJam](const auto& e) { return shouldJam(e.weight);});

    peck.erase(it2, peck.end());

    cout << "Weight of jam is: " << jamWeight << endl;
    for_each(peck.cbegin(), peck.cend(), [](const auto& e) { e.print(); });    
}