// Free the handsome prince.
// The dragon is a random age from 1 to 100 and is 5 years older every round.
// If the guess is too low the dragon says he is older; too high, younger.
// A correct guess ends the game.
//
//   Year 1000: Hello, fair maiden. I am a fearsome dragon. How old am I? 50
//   Wrong, I am older. No handsome prince for you. See you in five years.
//   Year 1005: Hello, fair maiden. I am a fearsome dragon. How old am I? 75
//   ...
//   You got it! Here is the handsome prince. Live happily ever after!
//
// While debugging, temporarily print the dragon's age so you can test a win.

#include <iostream>

int main() {
  int age;
  int guess;
  int year = 1000;

  while (true) {
    srand(time(nullptr));
    age = rand() % 100 + 1;

    std::cout << "Year " << year
              << ": Hello, fair maiden. I am a fearsome dragon. How old am I? ";
    std::cin >> guess;

    if (guess = age) {
      break;
    } else if (guess < age) {
      std::cout << "Wrong, I am younger. No handsome prince for you. "
                   "See you in five years."
                << std::endl;
    } else {
      std::cout << "Wrong, I am older. No handsome prince for you. "
                   "See you in five years."
                << std::endl;
    }

    year += 5;
    age += 5;
  }

  std::cout << "You got it! Here is the handsome prince. "
               "Live happily ever after!"
            << std::endl;
}
