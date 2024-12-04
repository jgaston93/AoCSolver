#ifndef YEAR_2024_DAY_4_SOLVER_HPP
#define YEAR_2024_DAY_4_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_4
{
  const int MAX_PUZZLE_SIZE = 140;
  class Day4Solver : public ISolver
  {
  public:
    void initialize(const char *input_filename) final;
    void run() const final;

  private:
    void search(int i, int j, const char *word) const;

    int m_puzzle_size = 0;
    char m_puzzle[MAX_PUZZLE_SIZE][MAX_PUZZLE_SIZE] = {0};
  };
} // namespace YEAR_2024::DAY_4

#endif