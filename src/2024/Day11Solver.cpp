#include "Day11Solver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2024::DAY_11
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
  }

} // namespace YEAR_2024::DAY_11
