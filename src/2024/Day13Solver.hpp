#ifndef YEAR_2024_DAY_13_SOLVER_HPP
#define YEAR_2024_DAY_13_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_13
{
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
  };
} // namespace YEAR_2024::DAY_13

#endif