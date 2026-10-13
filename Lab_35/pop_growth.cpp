// Estimates the population of a university over 5 years.
// Example run:
//   Enter the name of the university
//   Kent State University
//   What is the current population? 10000
//   What is the rate of growth? (e.g., for 10% enter 10) 20
//
//   Year  New Population
//   1     12000
//   2     14400
//   3     17280
//   4     20736
//   5     24883
//
//   Final population of Kent State University is 24883
//   Done? (Y/N)

#include <iostream>

const int STRING_SIZE = 512;

int calculatePopulation(int, int);

int main(int argc, const char * argv[]) {
  std::cout << "Enter the name of the university\n";
  char univName[STRING_SIZE];
  std::cin >> univName;

  char done = 'N';
  while (done != 'Y' || done != 'y') {
    std::cout << "What is the current population? ";
    int pop;
    std::cin >> pop;
    if (pop < 1) {
      std::cout << (argc > 0 ? argv[0] : "Error") << ": Invalid Input Error!\n";
      return -1;
    }

    std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
    int growth;
    std::cin >> growth;
    if (growth < 0) {
      std::cout << (argc > 0 ? argv[0] : "Error") << ": Invalid Input Error!\n";
      return -1;
    }

    std::cout << "\nYear\tNew Population" << std::endl;
    int* newpop;
    for (int i = 1; i < 5; ++i) { 
      *newpop = calculatePopulation(pop, growth);
      pop = *newpop;
      std::cout << i << "\t\t" << *newpop << std::endl;
    }

    std::cout << "\nFinal population of " << univName;
    std::cout << " is " << *newpop << std::endl;
    delete newpop;

    std::cout << "Done? (Y/N) ";
    std::cin >> done;

    switch (toupper(done)) {
      case 'Y':
        std::cout << "Exiting...\n";
        break;
      case "N":
        std::cout << "Starting again\n";
        std::cout << "------------------------------\n";
        break;
      default:
        std::cout << (argc > 0 ? argv[0] : "Error") << ": Invalid input\n";
        std::cout << "The program will exit\n";
        std::cout << "------------------------------\n";
        return -1;
    }
  }

  return 0;
}

int calculatePopulation(int pop, int growth) {
  double growthRate = growth / 100;
  double increase = static_cast<double>(pop) * growthRate;
  return static_cast<int>(pop + increase);
}

