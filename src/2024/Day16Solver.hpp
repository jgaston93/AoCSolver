#ifndef YEAR_2024_DAY_16_SOLVER_HPP
#define YEAR_2024_DAY_16_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

#include <limits>

using namespace AOC_SOLVER_COMMON;

namespace YEAR_2024::DAY_16
{

  const int MAX_MAP_SIZE = 141;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    void Move(int x, int y, Direction dir, int score);
    int m_map_size = 0;
    char m_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};
    int m_score_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {std::numeric_limits<int>::max()};
  };
} // namespace YEAR_2024::DAY_16

#endif