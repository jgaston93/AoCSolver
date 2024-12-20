#ifndef YEAR_2024_DAY_7_SOLVER_HPP
#define YEAR_2024_DAY_7_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_7
{

  using uint64_t = unsigned long long;
  enum class Operator
  {
    ADDITION,
    MULTIPLICATION,
    CONCATENATION
  };

  const int MAX_NUM_EQUATIONS = 850;
  const int MAX_NUM_TERMS = 32;

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_num_equations = 0;
    uint64_t m_test_values[MAX_NUM_EQUATIONS] = {0};
    uint64_t m_terms[MAX_NUM_EQUATIONS][MAX_NUM_TERMS] = {0};
    int m_num_terms[MAX_NUM_EQUATIONS] = {0};
  };
} // namespace YEAR_2024::DAY_7

#endif