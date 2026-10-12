#ifndef MAZE_HPP
#define MAZE_HPP

class Room {
public:
  Room(int x = 1, char y = 'a') : x_(x), y_(y) {}
  int x() const { return x_; }
  char y() const { return y_; }
  bool operator==(const Room &other) { return x_ == other.x_ && y_ == other.y_; }
  Room neighbor(char dir) const; // 'u', 'd', 'l' or 'r'
  bool inside() const;           // inside the 5x5 maze?
  void print() const;            // prints e.g. a1

private:
  int x_;  // column 1..5
  char y_; // row 'a'..'e'
}

class Maze {
public:
  Maze();
  void addWall(const Room &a, const Room &b);
  bool blocked(const Room &from, const Room &to) const;
  bool move(char dir); // true if the mouse moved
  bool won() const;
  Room mouse() const { return mouse_; }

private:
  static const int MAX_WALLS = 8;
  Room wallA_[MAX_WALLS];
  Room wallB_[MAX_WALLS];
  int numWalls_;
  Room mouse_;
};

#endif
