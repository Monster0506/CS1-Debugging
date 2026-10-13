# Lab_48 - Roster with a Student Class

Build with `g++ -std=c++17 -Wall rosterObject.cpp -o roster` and run `./roster cs1.txt cs2.txt cs3.txt dropouts.txt`. The expected output is in the comment at the top of `rosterObject.cpp`.

`std::list::sort`, `unique` and `remove` all depend on `operator<` and `operator==` of `Student`. Decide what makes two students equal and what ordering the list needs. Also think about what is left in an object after `std::move`.
