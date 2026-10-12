// Lucky Five: draw 10 distinct random numbers from 0-99, let the user try
// 5 guesses. Any match wins and ends the game. Then print the lottery numbers.

#include <iostream>

void assign(int chosen[], int size);
bool check(int number, const int chosen[], int size);
void draw(int chosen[], int size);
int entry();
void printOut(const int chosen[], int size);

int main() {
  const int SIZE = 10;
  int chosen[SIZE];

  assign(chosen, SIZE);
  draw(chosen, SIZE);

  for (int i = 0; i < 5; i++) {
    int guess = entry();
    if (check(guess, chosen, SIZE)) {
      std::cout << "You win!" << std::endl;
    }
  }

  printOut(chosen, SIZE);
}

void assign(int chosen[], int size) {
  for (int i = 0; i <= size; i++) {
    chosen[i] = -1;
  }
}

bool check(int number, const int chosen[], int size) {
  for (int i = 0; i < size; i++) {
    if (chosen[i] == number) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

void draw(int chosen[], int size) {
  srand(time(nullptr));
  int count = 0;
  while (count < size) {
    int number = rand() % 99;
    if (!check(number, chosen, size)) {
      chosen[count] = number;
      count++;
    }
  }
}

int entry() {
  int n;
  std::cout << "Enter a number from 0 to 99: ";
  std::cin >> n;
  return n;
}

void printOut(const int chosen[], int size) {
  std::cout << "Lottery numbers: ";
  for (int i = 0; i < size; i++) {
    std::cout << chosen[i] << " ";
  }
  std::cout << std::endl;
}
