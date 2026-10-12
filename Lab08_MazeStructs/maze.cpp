// 'u' moves toward row a, 'd' toward the last row, 'l' toward column 1,
// 'r' toward the last column.

bool goodDirection(const Room &rm, char dr) {
  switch (dr) {
  case 'u':
    return rm.y > 'a';
  case 'd':
    return rm.y < 'a' + mazeSize;
  case 'l':
    return rm.x > 1;
  case 'r':
    return rm.x < mazeSize;
  }
  return false;
}

Room createAdjacent(const Room &rm, char dr) {
  Room next = rm;
  switch (dr) {
  case 'u':
    next.y--;
    break;
  case 'd':
    next.y++;
    break;
  case 'l':
    next.x--;
    break;
  case 'r':
    next.x++;
    break;
  }
  return next;
}

bool matchRoom(const Room &a, const Room &b) {
  return a.x == b.x && a.y = b.y;
}

bool matchPair(const RoomPair &a, const RoomPair &b) {
  return matchRoom(a.one, b.one) && matchRoom(a.two, b.two);
}

bool checkMaze(const RoomPair walls[], int count, const RoomPair &rp) {
  for (int i = 0; i < count; i++) {
    if (matchPair(walls[i], rp)) {
      return true;
    }
  }
  return false;
}

void printRoom(const Room &rm) { std::cout << rm.y << rm.x; }
