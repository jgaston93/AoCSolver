#include "Day6Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_6
{

  enum class Direction
  {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
  };

  const int DIRECTIONS[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  void
  Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      int row_counter = 0;
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        if (m_map_size == 0)
        {
          int len = strlen(line);
          m_map_size = len;
        }
        strcpy(m_map[row_counter++], line);
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    Direction guard_direction = Direction::NONE;
    int guard_x = 0;
    int guard_y = 0;
    for (int i = 0; i < m_map_size && guard_direction == Direction::NONE; i++)
    {
      for (int j = 0; j < m_map_size && guard_direction == Direction::NONE; j++)
      {
        if (m_map[i][j] == '<')
        {
          guard_direction = Direction::LEFT;
        }
        else if (m_map[i][j] == '^')
        {
          guard_direction = Direction::UP;
        }
        else if (m_map[i][j] == '>')
        {
          guard_direction = Direction::RIGHT;
        }
        else if (m_map[i][j] == 'v')
        {
          guard_direction = Direction::DOWN;
        }

        if (guard_direction != Direction::NONE)
        {
          guard_x = j;
          guard_y = i;
        }
      }
    }

    bool guard_exited = false;
    while (!guard_exited)
    {
      int next_x = guard_x + DIRECTIONS[static_cast<int>(guard_direction)][0];
      int next_y = guard_y + DIRECTIONS[static_cast<int>(guard_direction)][1];

      if (0 > guard_x || guard_x >= m_map_size || 0 > guard_y || guard_y >= m_map_size)
      {
        guard_exited = true;
      }
      else if (m_map[next_y][next_x] == '#')
      {
        guard_direction = static_cast<Direction>(static_cast<int>(guard_direction) + 1);
        if (guard_direction == Direction::NONE)
          guard_direction = Direction::UP;
        next_x = guard_x + DIRECTIONS[static_cast<int>(guard_direction)][0];
        next_y = guard_y + DIRECTIONS[static_cast<int>(guard_direction)][1];
      }
      else if (m_map[next_y][next_x] == 'X')
      {
        m_map[next_y][next_x] = 'O';
      }

      if (!guard_exited)
      {
        if (m_map[guard_y][guard_x] != 'O')
          m_map[guard_y][guard_x] = 'X';
        guard_x = next_x;
        guard_y = next_y;
      }
    }

    int visit_count = 0;
    int obstacle_count = 0;
    for (int i = 0; i < m_map_size; i++)
    {
      for (int j = 0; j < m_map_size; j++)
      {
        printf("%c", m_map[i][j]);
        if (m_map[i][j] == 'X' || m_map[i][j] == 'O')
          visit_count++;
        if (m_map[i][j] == 'O')
          obstacle_count++;
      }
      printf("\n");
    }
    SetPart1Answer(visit_count);
    SetPart2Answer(obstacle_count);
  }

} // namespace YEAR_2024::DAY_3
