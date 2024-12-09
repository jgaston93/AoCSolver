#include "Day9Solver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2024::DAY_9
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      bool file_data = true;
      unsigned int file_count = 0;
      while (!feof(fp))
      {
        char c = fgetc(fp);

        if (file_data)
          file_count++;

        file_data = !file_data;
      }
      fclose(fp);

      printf("Max file count: %u\n", file_count);
    }
  }

  void Solver::Run()
  {
  }

} // namespace YEAR_2024::DAY_9
