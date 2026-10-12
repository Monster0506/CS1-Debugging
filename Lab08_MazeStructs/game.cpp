// Mouse maze game with a fixed set of walls.
// Walls (each blocks movement in BOTH directions):
//   a1|a2   b2|c2   c3|c4
// Expected behavior to test:
//   - from a1, 'r' is blocked ("wall"), 'd' works
//   - from a2, 'l' is blocked too (same wall, other direction)
//   - moving off the edge prints "wall" and keeps the mouse in place
//   - reaching e5 prints the win message

#include "maze.hpp"
#include <iostream>

int main() {
  RoomPair walls[] = {{{1, 'a'}, {2, 'a'}},
                      {{2, 'b'}, {2, 'c'}},
                      {{3, 'c'}, {4, 'c'}}};
  const int count = 3;

  Room mouse = startRoom;
  while (!matchRoom(mouse, cheeseRoom)) {
    printRoom(mouse);
    std::cout << " move [u/d/l/r/q]: ";
    char dr;
    std::cin >> dr;
    if (dr == 'q') {
      break;
    }
    if (!goodDirection(mouse, dr)) {
      std::cout << "wall" << std::endl;
      continue;
    }
    Room next = createAdjacent(mouse, dr);
    RoomPair step = {mouse, next};
    if (checkMaze(walls, count, step)) {
      std::cout << "wall" << std::endl;
    } else {
      mouse = next;
    }
  }

  if (matchRoom(mouse, cheeseRoom)) {
    std::cout << "The mouse found the cheese!" << std::endl;
  }
}
