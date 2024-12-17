#include "Day15Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_15
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      fgets(line, sizeof(line), fp);
      AOC_SOLVER_COMMON::StripNewlines(line);
      int len = strlen(line);
      if (m_map_size == 0)
        m_map_size = len;

      int row_index = 0;
      while (len > 0)
      {
        for (int i = 0; i < m_map_size; i++)
        {
          TileType type = TileType::SPACE;
          switch (line[i])
          {
          case '.':
            type = TileType::SPACE;
            break;
          case '#':
            type = TileType::OBSTACLE;
            break;
          case 'O':
            type = TileType::BOX;
            break;
          case '@':
            type = TileType::ROBOT;
            break;
          }

          m_map[row_index][i] = type;
        }
        row_index++;

        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        len = strlen(line);
      }

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        len = strlen(line);

        for (int i = 0; i < len; i++)
        {
          AOC_SOLVER_COMMON::Direction direction = AOC_SOLVER_COMMON::Direction::UP;
          switch (line[i])
          {
          case '^':
            direction = AOC_SOLVER_COMMON::Direction::UP;
            break;
          case '>':
            direction = AOC_SOLVER_COMMON::Direction::RIGHT;
            break;
          case 'v':
            direction = AOC_SOLVER_COMMON::Direction::DOWN;
            break;
          case '<':
            direction = AOC_SOLVER_COMMON::Direction::LEFT;
            break;
          }

          m_directions[m_num_directions++] = direction;
        }
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int x = 0;
    int y = 0;
    bool robot_found = false;
    for (int i = 0; i < m_map_size && !robot_found; i++)
    {
      for (int j = 0; j < m_map_size && !robot_found; j++)
      {
        if (m_map[i][j] == TileType::ROBOT)
        {
          y = i;
          x = j;
          robot_found = true;
        }
      }
    }

    for (int i = 0; i < m_num_directions; i++)
    {
      AOC_SOLVER_COMMON::Direction d = m_directions[i];

      int direction_index = 0;

      switch (d)
      {
      case AOC_SOLVER_COMMON::Direction::UP:
        direction_index = 0;
        break;
      case AOC_SOLVER_COMMON::Direction::RIGHT:
        direction_index = 1;
        break;
      case AOC_SOLVER_COMMON::Direction::DOWN:
        direction_index = 2;
        break;
      case AOC_SOLVER_COMMON::Direction::LEFT:
        direction_index = 3;
        break;
      }

      int vx = AOC_SOLVER_COMMON::DIRECTIONS[direction_index][0];
      int vy = AOC_SOLVER_COMMON::DIRECTIONS[direction_index][1];

      int next_x = x + vx;
      int next_y = y + vy;

      while (m_map[next_y][next_x] != TileType::SPACE && m_map[next_y][next_x] != TileType::OBSTACLE)
      {
        next_x = x + vx;
        next_y = y + vy;
      }

      if (m_map[next_y][next_x] == TileType::SPACE)
      {
        while (m_map[next_y][next_x] != TileType::ROBOT)
        {
          TileType t = m_map[next_y][next_x];
          m_map[next_y][next_x] = m_map[next_y - vy][next_x - vx];
          m_map[next_y - vy][next_x - vx] = t;
          next_x = next_x - vx;
          next_y = next_y - vy;
        }
      }
    }
  }

} // namespace YEAR_2024::DAY_15
