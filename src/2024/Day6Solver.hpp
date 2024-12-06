#ifndef YEAR_2024_DAY_6_SOLVER_HPP
#define YEAR_2024_DAY_6_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_6
{
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
  };
} // namespace YEAR_2024::DAY_6

#endif