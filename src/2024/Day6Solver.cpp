#include "Day6Solver.hpp"

#include <cstring>

namespace YEAR_2024::DAY_6
{
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
    AOC_SOLVER_COMMON::Direction start_direction = AOC_SOLVER_COMMON::Direction::NONE;
    int start_x = 0;
    int start_y = 0;
    for (int i = 0; i < m_map_size && start_direction == AOC_SOLVER_COMMON::Direction::NONE; i++)
    {
      for (int j = 0; j < m_map_size && start_direction == AOC_SOLVER_COMMON::Direction::NONE; j++)
      {
        if (m_map[i][j] == '<')
        {
          start_direction = AOC_SOLVER_COMMON::Direction::LEFT;
        }
        else if (m_map[i][j] == '^')
        {
          start_direction = AOC_SOLVER_COMMON::Direction::UP;
        }
        else if (m_map[i][j] == '>')
        {
          start_direction = AOC_SOLVER_COMMON::Direction::RIGHT;
        }
        else if (m_map[i][j] == 'v')
        {
          start_direction = AOC_SOLVER_COMMON::Direction::DOWN;
        }

        if (start_direction != AOC_SOLVER_COMMON::Direction::NONE)
        {
          start_x = j;
          start_y = i;
        }
      }
    }

    bool guard_visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = {false};
    bool guard_exited = false;
    bool loop_found = false;
    Walk(start_x, start_y, start_direction, guard_visited, guard_exited, loop_found);

    int visit_count = 0;
    int obstacle_count = 0;
    for (int i = 0; i < m_map_size; i++)
    {
      for (int j = 0; j < m_map_size; j++)
      {
        if (guard_visited[i][j])
        {
          // printf("X");
          visit_count++;

          char tile = m_map[i][j];
          m_map[i][j] = '#';
          bool v[MAX_MAP_SIZE][MAX_MAP_SIZE] = {false};
          Walk(start_x, start_y, start_direction, v, guard_exited, loop_found);
          if (loop_found)
            obstacle_count++;
          m_map[i][j] = tile;
        }
        else
        {
          // printf("%c", m_map[i][j]);
        }
      }
      // printf("\n");
    }

    SetPart1Answer(visit_count);
    SetPart2Answer(obstacle_count);
  }

  void Solver::Walk(int start_x, int start_y, AOC_SOLVER_COMMON::Direction start_direction, bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE], bool &guard_exited, bool &loop_found)
  {
    int guard_x = start_x;
    int guard_y = start_y;
    AOC_SOLVER_COMMON::Direction guard_direction = start_direction;

    bool directions[MAX_MAP_SIZE][MAX_MAP_SIZE][4] = {false};

    guard_exited = false;
    loop_found = false;
    while (!guard_exited && !loop_found)
    {
      int next_x = guard_x + AOC_SOLVER_COMMON::DIRECTIONS[static_cast<int>(guard_direction)][0];
      int next_y = guard_y + AOC_SOLVER_COMMON::DIRECTIONS[static_cast<int>(guard_direction)][1];

      while (0 <= next_x && next_x < m_map_size && 0 <= next_y && next_y < m_map_size && m_map[next_y][next_x] == '#')
      {
        if (directions[guard_y][guard_x][static_cast<int>(guard_direction)])
          loop_found = true;
        directions[guard_y][guard_x][static_cast<int>(guard_direction)] = true;

        guard_direction = static_cast<AOC_SOLVER_COMMON::Direction>(static_cast<int>(guard_direction) + 1);
        if (guard_direction == AOC_SOLVER_COMMON::Direction::NONE)
          guard_direction = AOC_SOLVER_COMMON::Direction::UP;
        next_x = guard_x + AOC_SOLVER_COMMON::DIRECTIONS[static_cast<int>(guard_direction)][0];
        next_y = guard_y + AOC_SOLVER_COMMON::DIRECTIONS[static_cast<int>(guard_direction)][1];
      }

      visited[guard_y][guard_x] = true;

      guard_x = next_x;
      guard_y = next_y;
      if (guard_x < 0 || m_map_size <= guard_x || guard_y < 0 || m_map_size <= guard_y)
      {
        guard_exited = true;
      }
    }
  }

} // namespace YEAR_2024::DAY_3
