#ifndef YEAR_2025_DAY_4_SOLVER_HPP
#define YEAR_2025_DAY_4_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2025::DAY_4
{
  const int MAX_SIZE_Y = 136;
  const int MAX_SIZE_X = 136;
  class Solver : public ISolver
  {
  public:
    Solver();
    void Initialize(const char *input_filename) final;
    void Run() final;
    void PrintAnswer() const final;

  private:
    char m_grid[MAX_SIZE_Y][MAX_SIZE_X];
    int m_size_y;
    int m_size_x;
  };
} // namespace YEAR_2024::DAY_4

#endif