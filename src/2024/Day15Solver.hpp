#ifndef YEAR_2024_DAY_15_SOLVER_HPP
#define YEAR_2024_DAY_15_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2024::DAY_15
{

  enum class TileType
  {
    SPACE,
    OBSTACLE,
    BOX,
    ROBOT
  };

  const int MAX_MAP_SIZE = 50;
  const int MAX_NUM_DIRECTIONS = 20000;

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_map_size = 0;
    TileType m_map[MAX_MAP_SIZE][MAX_MAP_SIZE];

    int m_num_directions = 0;
    AOC_SOLVER_COMMON::Direction m_directions[MAX_NUM_DIRECTIONS];
  };
} // namespace YEAR_2024::DAY_15

#endif