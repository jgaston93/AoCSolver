#ifndef YEAR_2024_DAY_1_SOLVER_HPP
#define YEAR_2024_DAY_1_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_1
{
  const int MAX_LIST_SIZE = 1000;
  class Day1Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    void CalculateScores(int &difference_score, int &similarity_score) const;
    void InsertLocationId(int location_id, int &count, int *location_id_list) const;
    int m_location_id_count_1 = 0;
    int m_location_id_count_2 = 0;
    int m_location_id_list_1[MAX_LIST_SIZE];
    int m_location_id_list_2[MAX_LIST_SIZE];

    int m_id_count = 0;
    int m_id_count_list[MAX_LIST_SIZE];
    int m_id_value_list[MAX_LIST_SIZE];
  };
} // namespace YEAR_2024::DAY_1

#endif