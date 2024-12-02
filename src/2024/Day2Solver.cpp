#include "Day2Solver.hpp"

#include "AOCSolverCommon.hpp"

#include <cstdio>

namespace YEAR_2024::DAY_2
{

  void Day2Solver::initialize(const char *input_filename)
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

  void Day2Solver::run() const
  {
    // printf("Part 1 = %d\n", difference_score);
    // printf("Part 2 = %d\n", similarity_score);
  }

} // namespace YEAR_2024::DAY_1
