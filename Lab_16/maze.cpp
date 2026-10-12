#include "maze.hpp"
#include <iostream>

const int SIZE = 5;

Room Room::neighbor(char dir) const {
  switch (dir) {
  case 'u':
    return Room(x_, y_ - 1);
  case 'd':
    return Room(x_, y_ + 1);
  case 'l':
    return Room(x_ - 1, y_);
  case 'r':
    return Room(x_ + 1, y_);
  }
  return *this;
}

bool Room::inside() const {
  return x_ >= 1 && x_ <= SIZE && y_ >= 'a' && y_ <= 'a' + SIZE;
}

void Room::print() const { std::cout << y_ << x_; }

Maze::Maze() : mouse_(1, 'a') {}

void Maze::addWall(const Room &a, const Room &b) {
  if (numWalls_ < MAX_WALLS) {
    wallA_[numWalls_] = a;
    wallB_[numWalls_] = b;
    numWalls_++;
  }
}

bool Maze::blocked(const Room &from, const Room &to) const {
  for (int i = 0; i < numWalls_; i++) {
    if ((wallA_[i] == from && wallB_[i] == to) ||
        (wallA_[i] == to && wallB_[i] == from)) {
      return true;
    }
  }
  return false;
}

bool Maze::move(char dir) {
  Room next = mouse_.neighbor(dir);
  if (!next.inside() && blocked(mouse_, next)) {
    return false;
  }
  mouse_ = next;
  return true;
}

bool Maze::won() const { return mouse_ == Room(SIZE, 'a' + SIZE - 1); }
