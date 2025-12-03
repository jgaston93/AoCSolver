#ifndef YEAR_2025_DAY_3_SOLVER_HPP
#define YEAR_2025_DAY_3_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2025::DAY_3
{
  const int MAX_COL = 101;
  const int MAX_ROW = 200;
  class Solver : public ISolver
  {
  public:
    Solver();
    void Initialize(const char *input_filename) final;
    void Run() final;
    void PrintAnswer() const final;

  private:
    char m_battery_banks[MAX_ROW][MAX_COL];
    int m_num_banks;
    int m_bank_size;
  };
} // namespace YEAR_2024::DAY_3

#endif