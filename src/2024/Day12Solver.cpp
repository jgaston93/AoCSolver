#include "Day12Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_12
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int counter = 0;
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        if (m_map_size == 0)
        {
          m_map_size = strlen(line);
        }

        for (int i = 0; i < m_map_size; i++)
        {
          m_map[counter][i].type = line[i];
        }
        counter++;
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = {false};

    for (int i = 0; i < m_map_size; i++)
    {
      for (int j = 0; j < m_map_size; j++)
      {
        if (!visited[i][j])
        {
          int fence[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2] = {0};
          m_types[m_next_tile_id] = m_map[i][j].type;
          Walk(j, i, m_next_tile_id, visited, fence);

          for (int y = 0; y < m_map_size + 2; y++)
          {
            for (int x = 0; x < m_map_size + 2; x++)
            {
              m_perimeters[m_next_tile_id] += fence[y][x];
            }
          }
          m_next_tile_id++;
        }
      }
    }
    int price = 0;
    for (int i = 0; i < m_next_tile_id; i++)
    {
      price += m_perimeters[i] * m_areas[i];
    }
    SetPart1Answer(price);
  }

  void Solver::Walk(int x, int y, int id, bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE], int fence[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2])
  {
    m_map[y][x].id = id;
    visited[y][x] = true;
    m_areas[id]++;

    for (int i = 0; i < 4; i++)
    {
      int next_x = x + AOC_SOLVER_COMMON::DIRECTIONS[i][0];
      int next_y = y + AOC_SOLVER_COMMON::DIRECTIONS[i][1];

      if (0 <= next_x && next_x < m_map_size && 0 <= next_y && next_y < m_map_size)
      {
        if (!visited[next_y][next_x] && m_map[next_y][next_x].type == m_map[y][x].type)
        {
          Walk(next_x, next_y, id, visited, fence);
        }
        else if (m_map[next_y][next_x].type != m_map[y][x].type)
        {
          fence[next_y + 1][next_x + 1]++;
        }
      }
      else
      {
        fence[next_y + 1][next_x + 1]++;
      }
    }
  }

} // namespace YEAR_2024::DAY_12
