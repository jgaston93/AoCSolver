#ifndef AOC_SOLVER_COMMON_HPP
#define AOC_SOLVER_COMMON_HPP

namespace AOC_SOLVER_COMMON
{
  const int MAX_LINE_LENGTH = 256;

  const int DIRECTIONS[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  const char DIRECTION_CHAR[4] = {'^', '>', 'v', '<'};
  enum class Direction
  {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
  };

  void StripNewlines(char *str);
}

#endif
