# Lab_56 - Abstract Factory: Car Dealership

Build with `g++ -std=c++17 -Wall -g CarFactory.cpp CarBuyer.cpp -o dealer` and also run under `valgrind ./dealer`. The expected behavior is in the comment at the top of `CarBuyer.cpp`.

While debugging, replace `srand(time(nullptr))` with `srand(1)`. Check every member variable: is it initialized before it is used?
