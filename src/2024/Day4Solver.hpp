#ifndef YEAR_2024_DAY_4_SOLVER_HPP
#define YEAR_2024_DAY_4_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_4
{
  const int MAX_PUZZLE_SIZE = 140;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int Search(int row, int col, const int num_filters, const char filters[8][4][4], const int *filter_widths, const int *filter_heights) const;

    int m_puzzle_size = 0;
    char m_puzzle[MAX_PUZZLE_SIZE][MAX_PUZZLE_SIZE] = {0};
  };
} // namespace YEAR_2024::DAY_4

#endif