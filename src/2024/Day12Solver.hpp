#ifndef YEAR_2024_DAY_12_SOLVER_HPP
#define YEAR_2024_DAY_12_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_12
{
  const int MAX_MAP_SIZE = 141;
  const int MAX_TILE_ID = 600;

  struct Tile
  {
    char type = 0;
    unsigned int id = 0;
  };

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    void Walk(int x, int y, int id, bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE], bool fence[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2]);
    int m_map_size = 0;
    Tile m_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};
    int m_next_tile_id = 0;
    int m_areas[MAX_TILE_ID] = {0};
    int m_perimeters[MAX_TILE_ID] = {0};
    char m_types[MAX_TILE_ID] = {0};
  };
} // namespace YEAR_2024::DAY_12

#endif