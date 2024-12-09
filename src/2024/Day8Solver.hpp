#ifndef YEAR_2024_DAY_8_SOLVER_HPP
#define YEAR_2024_DAY_8_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_8
{
  const int MAX_SIZE = 51;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_size = 0;
    char m_map[MAX_SIZE][MAX_SIZE] = {0};
    bool m_antinode_map[MAX_SIZE][MAX_SIZE] = {false};
    bool m_harmonics_map[MAX_SIZE][MAX_SIZE] = {false};
  };
} // namespace YEAR_2024::DAY_8

#endif