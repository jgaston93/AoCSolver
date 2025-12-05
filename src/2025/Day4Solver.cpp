#include "Day4Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <string.h>
namespace YEAR_2025::DAY_4
{
  Solver::Solver() : m_size_y(0), m_size_x(0)
  {
    for (int i = 0; i < MAX_SIZE_Y; i++)
    {
      memset(m_grid[i], '\0', MAX_SIZE_X);
    }
  }

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        memcpy(m_grid[m_size_y++], line, strlen(line));
        m_size_x = strlen(line);
      }

      fclose(fp);
    }
  }

  void Solver::Run()
  {
    unsigned long long int part1_answer = 0;
    unsigned long long int part2_answer = 0;

    unsigned long long int rolls_removed = 0;
    unsigned long long int previous_rolls_removed = 0;
    bool removed_rolls = true;
    while (removed_rolls)
    {
      for (int y = 0; y < m_size_y; y++)
      {
        for (int x = 0; x < m_size_x; x++)
        {
          if (m_grid[y][x] == '@')
          {
            int y_1 = y - 1;
            int y_2 = y + 1;
            int x_1 = x - 1;
            int x_2 = x + 1;

            if (y_1 < 0)
            {
              y_1 = 0;
            }
            if (y_2 > m_size_y - 1)
            {
              y_2 = m_size_y - 1;
            }
            if (x_1 < 0)
            {
              x_1 = 0;
            }
            if (x_2 > m_size_x - 1)
            {
              x_2 = m_size_x - 1;
            }

            int roll_count = 0;

            for (int i = y_1; i <= y_2; i++)
            {
              for (int j = x_1; j <= x_2; j++)
              {
                if (!(i == y && j == x) && m_grid[i][j] == '@')
                {
                  roll_count++;
                }
              }
            }
            if (roll_count < 4)
            {
              part1_answer++;
              m_grid[y][x] = '.';
              rolls_removed++;
            }
          }
        }
      }

      if (rolls_removed == previous_rolls_removed)
      {
        removed_rolls = false;
      }
      previous_rolls_removed = rolls_removed;
    }

    for (int y = 0; y < m_size_y; y++)
    {
      for (int x = 0; x < m_size_x; x++)
      {
        printf("%c", m_grid[y][x]);
      }
      printf("\n");
    }

    printf("part1_answer=%llu\n", part1_answer);

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }

  void Solver::PrintAnswer() const
  {
  }
} // namespace YEAR_2024::DAY_4
