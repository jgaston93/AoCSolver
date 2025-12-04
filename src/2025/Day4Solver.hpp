#ifndef YEAR_2025_DAY_4_SOLVER_HPP
#define YEAR_2025_DAY_4_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2025::DAY_4
{
  class Solver : public ISolver
  {
  public:
    Solver();
    void Initialize(const char *input_filename) final;
    void Run() final;
    void PrintAnswer() const final;

  private:
  };
} // namespace YEAR_2024::DAY_4

#endif