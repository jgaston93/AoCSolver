#include "Day1Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <math.h>

namespace YEAR_2025::DAY_1
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int part1_answer = 0;
    int part2_answer = 0;

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }
} // namespace YEAR_2024::DAY_1
