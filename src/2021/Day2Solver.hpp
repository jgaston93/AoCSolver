#ifndef YEAR_2021_DAY_2_SOLVER_HPP
#define YEAR_2021_DAY_2_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2021::DAY_2
{
  const int MAX_COMMAND_COUNT = 1000;

  enum class Direction
  {
    Forward,
    Up,
    Down,
    Max,
  };

  struct Command
  {
    Direction direction = Direction::Max;
    int distance = 0;
  };

  class Day2Solver : public ISolver
  {
  public:
    void initialize(const char *input_filename) final;
    void run() const final;

  private:
    int m_command_count = 0;
    Command m_commands[MAX_COMMAND_COUNT];
  };
} // namespace YEAR_2021::DAY_2

#endif