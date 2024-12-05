#ifndef YEAR_2024_DAY_5_SOLVER_HPP
#define YEAR_2024_DAY_5_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_5
{
  const int MAX_NUM_RULES = 1176;
  const int MAX_NUM_UPDATES = 189;
  const int MAX_NUM_PAGES = 23;
  class Day5Solver : public ISolver
  {
  public:
    void initialize(const char *input_filename) final;
    void run() const final;

  private:
    int m_ordering_list_1[MAX_NUM_RULES] = {0};
    int m_ordering_list_2[MAX_NUM_RULES] = {0};

    int m_updates[MAX_NUM_UPDATES][MAX_NUM_PAGES] = {0};
    int m_update_lengths[MAX_NUM_UPDATES] = {0};
  };
} // namespace YEAR_2024::DAY_5

#endif