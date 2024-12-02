#ifndef YEAR_2024_DAY_2_SOLVER_HPP
#define YEAR_2024_DAY_2_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_2
{

  class Day2Solver : public ISolver
  {
  public:
    void initialize(const char *input_filename) final;
    void run() const final;

  private:
  };
} // namespace YEAR_2024::DAY_2

#endif