#ifndef YEAR_2024_DAY_6_SOLVER_HPP
#define YEAR_2024_DAY_6_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_6
{
  const int MAX_MAP_SIZE = 131;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_map_size = 0;
    char m_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};
  };
} // namespace YEAR_2024::DAY_6

#endif