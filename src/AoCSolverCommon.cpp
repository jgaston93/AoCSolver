#include "AoCSolverCommon.hpp"

namespace AOC_SOLVER_COMMON
{
  void StripNewlines(char *str)
  {
    int index = 0;
    char c = str[index];
    bool newline_found = false;
    while (newline_found && c != '\0')
    {
      c = str[index];
      if (c == '\r' || c == '\n')
        newline_found = true;
      index++;
    }
    if (newline_found)
      str[index - 1] = '\0';
  }
}