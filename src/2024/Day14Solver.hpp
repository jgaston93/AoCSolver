#ifndef YEAR_2024_DAY_14_SOLVER_HPP
#define YEAR_2024_DAY_14_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_14
{
  const int MAX_NUM_ROBOTS = 500;
  const int ROOM_WIDTH = 101;
  const int ROOM_HEIGHT = 103;
  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_num_robots = 0;
    int m_x[MAX_NUM_ROBOTS] = {0};
    int m_y[MAX_NUM_ROBOTS] = {0};
    int m_vx[MAX_NUM_ROBOTS] = {0};
    int m_vy[MAX_NUM_ROBOTS] = {0};
  };
} // namespace YEAR_2024::DAY_14

#endif