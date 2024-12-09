#include "Day8Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>
#include <math.h>

namespace YEAR_2024::DAY_8
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int line_counter = 0;
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        if (m_size == 0)
        {
          m_size = strlen(line);
        }
        strcpy(m_map[line_counter++], line);
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    for (int y1 = 0; y1 < m_size; y1++)
    {
      for (int x1 = 0; x1 < m_size; x1++)
      {
        char c = m_map[y1][x1];
        if (c != '.')
        {
          for (int y2 = 0; y2 < m_size; y2++)
          {
            for (int x2 = 0; x2 < m_size; x2++)
            {
              if (x1 != x2 && y1 != y2 && m_map[y1][x1] == m_map[y2][x2])
              {
                int x_distance = abs(x1 - x2);
                int y_distance = abs(y1 - y2);

                int antinode1_x_dir = 0;
                int antinode1_y_dir = 0;
                int antinode2_x_dir = 0;
                int antinode2_y_dir = 0;

                if (x1 > x2 && y1 > y2)
                {
                  antinode1_x_dir = x_distance;
                  antinode1_y_dir = y_distance;

                  antinode2_x_dir = -x_distance;
                  antinode2_y_dir = -y_distance;
                }
                else if (x1 > x2 && y1 < y2)
                {
                  antinode1_x_dir = +x_distance;
                  antinode1_y_dir = -y_distance;

                  antinode2_x_dir = -x_distance;
                  antinode2_y_dir = +y_distance;
                }
                else if (x1 < x2 && y1 > y2)
                {
                  antinode1_x_dir = -x_distance;
                  antinode1_y_dir = y_distance;

                  antinode2_x_dir = x_distance;
                  antinode2_y_dir = -+y_distance;
                }
                else if (x1 < x2 && y1 < y2)
                {
                  antinode1_x_dir = -x_distance;
                  antinode1_y_dir = -y_distance;

                  antinode2_x_dir = x_distance;
                  antinode2_y_dir = y_distance;
                }

                int antinode1_x = x1 + antinode1_x_dir;
                int antinode1_y = y1 + antinode1_y_dir;
                int antinode2_x = x2 + antinode2_x_dir;
                int antinode2_y = y2 + antinode2_y_dir;

                if (0 <= antinode1_x && antinode1_x < m_size && 0 <= antinode1_y && antinode1_y < m_size)
                {
                  m_antinode_map[antinode1_y][antinode1_x] = true;
                }

                if (0 <= antinode2_x && antinode2_x < m_size && 0 <= antinode2_y && antinode2_y < m_size)
                {
                  m_antinode_map[antinode2_y][antinode2_x] = true;
                }

                m_harmonics_map[y1][x1] = true;
                m_harmonics_map[y2][x2] = true;

                while (0 <= antinode1_x && antinode1_x < m_size && 0 <= antinode1_y && antinode1_y < m_size)
                {
                  m_harmonics_map[antinode1_y][antinode1_x] = true;
                  antinode1_x += antinode1_x_dir;
                  antinode1_y += antinode1_y_dir;
                }

                while (0 <= antinode2_x && antinode2_x < m_size && 0 <= antinode2_y && antinode2_y < m_size)
                {
                  m_harmonics_map[antinode2_y][antinode2_x] = true;
                  antinode2_x += antinode2_x_dir;
                  antinode2_y += antinode2_y_dir;
                }
              }
            }
          }
        }
      }
    }

    int antinode_count = 0;
    int harmonics_count = 0;
    for (int i = 0; i < m_size; i++)
    {
      for (int j = 0; j < m_size; j++)
      {
        if (m_antinode_map[i][j])
        {
          antinode_count++;
        }

        if (m_harmonics_map[i][j])
        {
          harmonics_count++;
        }
      }
    }
    SetPart1Answer(antinode_count);
    SetPart2Answer(harmonics_count);
  }

} // namespace YEAR_2024::DAY_8
