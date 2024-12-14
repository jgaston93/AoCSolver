#ifndef YEAR_2024_DAY_13_SOLVER_HPP
#define YEAR_2024_DAY_13_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_13
{
  const int MAX_NUM_MACHNES = 320;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_num_machines = 0;
    int m_a_x[MAX_NUM_MACHNES] = {0};
    int m_a_y[MAX_NUM_MACHNES] = {0};
    int m_b_x[MAX_NUM_MACHNES] = {0};
    int m_b_y[MAX_NUM_MACHNES] = {0};
    int m_prize_x[MAX_NUM_MACHNES] = {0};
    int m_prize_y[MAX_NUM_MACHNES] = {0};
  };
} // namespace YEAR_2024::DAY_13

#endif