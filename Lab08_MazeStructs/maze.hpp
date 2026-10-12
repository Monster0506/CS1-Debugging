#ifndef MAZE_HPP
#define MAZE_HPP

const int mazeSize = 5; // maze is mazeSize * mazeSize

struct Room {
  int x;  // 1 through mazeSize (column)
  char y; // 'a' through 'a' + mazeSize - 1 (row)
};

const Room startRoom = {1, 'a'};
const Room cheeseRoom = {mazeSize, 'a' + mazeSize - 1};

// a wall between two adjacent rooms; one|two is the same wall as two|one
struct RoomPair {
  Room one;
  Room two;
};

// true if moving in direction dr ('u', 'd', 'l', 'r') keeps us inside the maze
bool goodDirection(const Room &rm, char dr);

// the room next to rm in direction dr
Room createAdjacent(const Room &rm, char dr);

bool matchRoom(const Room &a, const Room &b);
bool matchPair(const RoomPair &a, const RoomPair &b);

// true if rp matches one of the first count walls in the array
bool checkMaze(const RoomPair walls[], int count, const RoomPair &rp);

void printRoom(const Room &rm); // prints e.g. a1

#endif
