#ifndef YEAR_2024_DAY_11_SOLVER_HPP
#define YEAR_2024_DAY_11_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_11
{
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
  };
} // namespace YEAR_2024::DAY_11

#endif