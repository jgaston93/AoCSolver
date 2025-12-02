#include "Day1Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdlib>

namespace YEAR_2025::DAY_1
{
  Solver::Solver() : num_rotations(0)
  {
  }

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        Rotation r;

        if (line[0] == 'R')
        {
          r.direction = AOC_SOLVER_COMMON::Direction::RIGHT;
        }
        else if (line[0] == 'L')
        {
          r.direction = AOC_SOLVER_COMMON::Direction::LEFT;
        }
        r.count = atoi(&line[1]);

        rotations[num_rotations++] = r;
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int part1_answer = 0;
    int part2_answer = 0;

    int dial_position = 50;

    for (int i = 0; i < num_rotations; i++)
    {
      int direction;
      if (rotations[i].direction == AOC_SOLVER_COMMON::Direction::RIGHT)
      {
        direction = 1;
      }
      else if (rotations[i].direction == AOC_SOLVER_COMMON::Direction::LEFT)
      {
        direction = -1;
      }

      for (int j = 0; j < rotations[i].count; j++)
      {
        dial_position += direction;
        dial_position = (dial_position % 100 + 100) % 100;
        if (dial_position == 0)
        {
          part2_answer++;
        }
      }

      if (dial_position == 0)
      {
        part1_answer++;
      }
    }

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }
} // namespace YEAR_2024::DAY_1
