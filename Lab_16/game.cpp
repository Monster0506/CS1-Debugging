// Mouse maze game using classes.
// Walls: a1|a2   b2|c2   c3|c4   (block both directions)
// Test: from a1 'r' prints "wall", 'd' works, the edges hold, e5 wins.

#include "maze.hpp"
#include <iostream>

int main() {
  Maze maze();
  maze.addWall(Room(1, 'a'), Room(2, 'a'));
  maze.addWall(Room(2, 'b'), Room(2, 'c'));
  maze.addWall(Room(3, 'c'), Room(4, 'c'));

  while (!maze.won()) {
    maze.mouse().print();
    std::cout << " move [u/d/l/r/q]: ";
    char dir;
    std::cin >> dir;
    if (dir == 'q') {
      break;
    }
    if (!maze.move(dir)) {
      std::cout << "wall" << std::endl;
    }
  }

  if (maze.won()) {
    std::cout << "The mouse found the cheese!" << std::endl;
  }
}
