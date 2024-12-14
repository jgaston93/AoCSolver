#include "Day14Solver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2024::DAY_14
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);

        sscanf(line, "p=%d,%d v=%d,%d", &m_x[m_num_robots], &m_y[m_num_robots], &m_vx[m_num_robots], &m_vy[m_num_robots]);
        m_num_robots++;
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int quadrant_counts[4] = {0};
    for (int i = 0; i < m_num_robots; i++)
    {
      m_x[i] = (m_x[i] + m_vx[i] * 100) % ROOM_WIDTH;
      m_y[i] = (m_y[i] + m_vy[i] * 100) % ROOM_HEIGHT;

      if (m_x[i] < 0)
        m_x[i] = ROOM_WIDTH + m_x[i];
      if (m_y[i] < 0)
        m_y[i] = ROOM_HEIGHT + m_y[i];

      if (m_x[i] < (ROOM_WIDTH - 1) / 2 && m_y[i] < (ROOM_HEIGHT - 1) / 2)
      {
        quadrant_counts[0]++;
      }
      else if (m_x[i] > (ROOM_WIDTH - 1) / 2 && m_y[i] < (ROOM_HEIGHT - 1) / 2)
      {
        quadrant_counts[1]++;
      }
      else if (m_x[i] < (ROOM_WIDTH - 1) / 2 && m_y[i] > (ROOM_HEIGHT - 1) / 2)
      {
        quadrant_counts[2]++;
      }
      else if (m_x[i] > (ROOM_WIDTH - 1) / 2 && m_y[i] > (ROOM_HEIGHT - 1) / 2)
      {
        quadrant_counts[3]++;
      }
    }

    int map[ROOM_HEIGHT][ROOM_WIDTH] = {0};
    for (int i = 0; i < m_num_robots; i++)
    {
      if (0 <= m_x[i] && m_x[i] < ROOM_WIDTH && 0 <= m_y[i] && m_y[i] < ROOM_HEIGHT)
      {
        map[m_y[i]][m_x[i]] += 1;
      }
      else
      {
        printf("INVALID POSITION [%d]: %d %d\n", i, m_x[i], m_y[i]);
      }
    }

    for (int i = 0; i < ROOM_HEIGHT; i++)
    {
      for (int j = 0; j < ROOM_WIDTH; j++)
      {
        if (i == (ROOM_HEIGHT - 1) / 2 || j == (ROOM_WIDTH - 1) / 2)
        {
          printf(" ");
        }
        else if (map[i][j] == 0)
        {
          printf(".");
        }
        else
        {
          printf("%d", map[i][j]);
        }
      }
      printf("\n");
    }

    SetPart1Answer(quadrant_counts[0] * quadrant_counts[1] * quadrant_counts[2] * quadrant_counts[3]);
  }

} // namespace YEAR_2024::DAY_14
