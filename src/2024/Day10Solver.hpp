#ifndef YEAR_2024_DAY_10_SOLVER_HPP
#define YEAR_2024_DAY_10_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_10
{
  const int MAX_MAP_SIZE = 51;
  const int MAX_NUM_TRAILHEADS = 260;

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int WalkTrails(int x, int y, bool destination_map[MAX_MAP_SIZE][MAX_MAP_SIZE], char trail_map[MAX_MAP_SIZE][MAX_MAP_SIZE]);
    int m_map_size = 0;
    int m_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};

    int m_num_trailheads = 0;
    int m_trailheads_x[MAX_NUM_TRAILHEADS] = {0};
    int m_trailheads_y[MAX_NUM_TRAILHEADS] = {0};
  };
} // namespace YEAR_2024::DAY_10

#endif