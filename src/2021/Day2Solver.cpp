#include "Day2Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdio>
#include <string.h>

namespace YEAR_2021::DAY_2
{
  Direction getDirection(const char *direction_str)
  {
    Direction d = Direction::Max;
    if (strcmp(direction_str, "forward") == 0)
    {
      d = Direction::Forward;
    }
    else if (strcmp(direction_str, "up") == 0)
    {
      d = Direction::Up;
    }
    else if (strcmp(direction_str, "down") == 0)
    {
      d = Direction::Down;
    }
    else
    {
      printf("getDirection: Invalid string found\n");
    }
    return d;
  }

  void Day2Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      while (!feof(fp))
      {
        char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
        fgets(line, sizeof(line), fp);

        char direction[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
        int distance = 0;
        sscanf(line, "%s %d", direction, &distance);

        m_commands[m_command_count++] = {getDirection(direction), distance};
      }
      fclose(fp);
    }
  }

  void Day2Solver::run()
  {
    int x = 0;
    int y = 0;
    int y_with_aim = 0;

    for (int i = 0; i < m_command_count; i++)
    {
      Command command = m_commands[i];
      if (command.direction == Direction::Forward)
      {
        x += command.distance;
        y_with_aim += command.distance * y;
      }
      else
      {
        int distance = command.distance;
        int direction = 0;
        if (command.direction == Direction::Down)
        {
          direction = 1;
        }
        else if (command.direction == Direction::Up)
        {
          direction = -1;
        }
        else
        {
          printf("run: Invalid direction found\n");
        }

        y += distance * direction;
      }
    }

    printf("Part 1 = %d\n", x * y);
    printf("Part 2 = %d\n", x * y_with_aim);
  }
} // namespace YEAR_2021::DAY_2 // namespace YEAR_2021