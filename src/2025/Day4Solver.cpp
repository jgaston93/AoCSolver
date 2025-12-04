#include "Day4Solver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2025::DAY_4
{
  Solver::Solver()
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
      }

      fclose(fp);
    }
  }

  void Solver::Run()
  {
    unsigned long long int part1_answer;
    unsigned long long int part2_answer;

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }

  void Solver::PrintAnswer() const
  {
  }
} // namespace YEAR_2024::DAY_4
