#include "Day10Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_10
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
          m_map[counter][i] = line[i] - '0';
        }
        counter++;
      }
      fclose(fp);

      for (int i = 0; i < m_map_size; i++)
      {
        for (int j = 0; j < m_map_size; j++)
        {
          if (m_map[i][j] == 0)
          {
            m_trailheads_x[m_num_trailheads] = j;
            m_trailheads_y[m_num_trailheads] = i;
            m_num_trailheads++;
          }
        }
      }
    }
  }

  void Solver::Run()
  {
    int trailhead_score_sum = 0;
    int trailhead_rating_sum = 0;
    for (int i = 0; i < m_num_trailheads; i++)
    {
      int trailhead_score = 0;
      int trailhead_rating = 0;
      bool destination_map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {false};
      char trail_map[MAX_MAP_SIZE][MAX_MAP_SIZE];
      for (int j = 0; j < m_map_size; j++)
      {
        for (int k = 0; k < m_map_size; k++)
        {
          if (j == m_trailheads_y[i] && k == m_trailheads_x[i])
            trail_map[j][k] = 'S';
          else
            trail_map[j][k] = '.';
          destination_map[j][k] = false;
        }
      }
      trailhead_rating += WalkTrails(m_trailheads_x[i], m_trailheads_y[i], destination_map, trail_map);
      for (int j = 0; j < m_map_size; j++)
      {
        for (int k = 0; k < m_map_size; k++)
        {
          if (destination_map[j][k])
            trailhead_score++;
        }
      }
      trailhead_score_sum += trailhead_score;
      trailhead_rating_sum += trailhead_rating;
    }
    SetPart1Answer(trailhead_score_sum);
    SetPart2Answer(trailhead_rating_sum);
  }

  int Solver::WalkTrails(int x, int y, bool destination_map[MAX_MAP_SIZE][MAX_MAP_SIZE], char trail_map[MAX_MAP_SIZE][MAX_MAP_SIZE])
  {
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
      int next_x = x + AOC_SOLVER_COMMON::DIRECTIONS[i][0];
      int next_y = y + AOC_SOLVER_COMMON::DIRECTIONS[i][1];
      if (0 <= next_x && next_x < m_map_size && 0 <= next_y && next_y < m_map_size)
      {
        if (m_map[next_y][next_x] == m_map[y][x] + 1)
        {
          if (m_map[next_y][next_x] == 9)
          {
            destination_map[next_y][next_x] = true;
            trail_map[next_y][next_x] = 'X';
            result += 1;
          }
          else
          {
            trail_map[next_y][next_x] = AOC_SOLVER_COMMON::DIRECTION_CHAR[i];
            result += WalkTrails(next_x, next_y, destination_map, trail_map);
          }
        }
      }
    }
    return result;
  }

} // namespace YEAR_2024::DAY_10
