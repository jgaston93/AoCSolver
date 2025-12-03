#ifndef YEAR_2025_DAY_2_SOLVER_HPP
#define YEAR_2025_DAY_2_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

#include <string.h>

namespace YEAR_2025::DAY_2
{
  const int MAX_NUM_CHARACTERS = 21;
  const int MAX_NUM_RANGES = 40;
  struct ProductIDRange
  {
    char start[MAX_NUM_CHARACTERS];
    int length;

    ProductIDRange() : length(0)
    {
      memset(start, 0, sizeof(start));
    }
  };

  class Solver : public ISolver
  {
  public:
    Solver();
    void Initialize(const char *input_filename) final;
    void Run() final;
    void PrintAnswer() const final;

  private:
    ProductIDRange ranges[MAX_NUM_RANGES];
    int num_ranges;
  };
} // namespace YEAR_2024::DAY_2

#endif