#ifndef YEAR_2024_DAY_7_SOLVER_HPP
#define YEAR_2024_DAY_7_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_7
{
  const int MAX_NUM_EQUATIONS = 850;
  const int MAX_EQ_VALUES = 32;

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    unsigned int m_num_equations = 0;
    unsigned int m_test_values[MAX_NUM_EQUATIONS] = {0};
    unsigned int m_eq_values[MAX_NUM_EQUATIONS][MAX_EQ_VALUES] = {0};
    unsigned int m_eq_value_counts[MAX_NUM_EQUATIONS] = {0};
  };
} // namespace YEAR_2024::DAY_7

#endif