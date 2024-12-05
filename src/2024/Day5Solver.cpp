#include "Day5Solver.hpp"

#include "AOCSolverCommon.hpp"

#include <cstdio>
#include <cstring>

namespace YEAR_2024::DAY_5
{

  void
  Day5Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int row_index = 0;
      while (strlen(line) > 1)
      {
        fgets(line, sizeof(line), fp);
        if (strlen(line) > 1)
          printf("%s", line);
      }

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        printf("%s", line);
      }
      fclose(fp);
    }
  }

  void Day5Solver::run() const
  {
    // printf("Part 1 = %d\n", words_found);
    // printf("Part 2 = %d\n", xmas_found);
  }

} // namespace YEAR_2024::DAY_5
