#ifndef YEAR_2025_DAY_1_SOLVER_HPP
#define YEAR_2025_DAY_1_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2025::DAY_1
{
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
  };
} // namespace YEAR_2024::DAY_1

#endif