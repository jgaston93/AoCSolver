#ifndef YEAR_2024_DAY_10_SOLVER_HPP
#define YEAR_2024_DAY_10_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_10
{
  const int MAX_MAP_SIZE = 51;
  const int MAX_NUM_TRAILHEADS = 260;
  struct Node
  {
    int height = 0;
    int x = 0;
    int y = 0;
    int num_next_nodes = 0;
    Node **next_nodes;
  };

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_map_size = 0;
    char m_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};

    int m_num_trailheads = 0;
    Node *m_trailheads[MAX_NUM_TRAILHEADS];
  };
} // namespace YEAR_2024::DAY_10

#endif