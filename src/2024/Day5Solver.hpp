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
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    bool Compare(int a, int b);
    void Sort(int *arr, int size);
    int m_num_rules = 0;
    int m_rules_list_1[MAX_NUM_RULES] = {0};
    int m_rules_list_2[MAX_NUM_RULES] = {0};

    int m_mrl_size = 0;
    int m_master_rule_list[MAX_NUM_RULES * 2] = {0};

    int m_num_updates = 0;
    int m_updates[MAX_NUM_UPDATES][MAX_NUM_PAGES] = {0};
    int m_update_lengths[MAX_NUM_UPDATES] = {0};
  };
} // namespace YEAR_2024::DAY_5

#endif