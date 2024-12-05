#include "Day3Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdio>

namespace YEAR_2024::DAY_3
{

  void Day3Solver::initialize(const char *input_filename)
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

  void Day3Solver::run()
  {
    // printf("Part 1 = %d\n", safe_report_count);
    // printf("Part 2 = %d\n", dampened_report_count);
  }

} // namespace YEAR_2024::DAY_3
