#ifndef YEAR_2024_DAY_3_SOLVER_HPP
#define YEAR_2024_DAY_3_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_3
{
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
  };
} // namespace YEAR_2024::DAY_3

#endif