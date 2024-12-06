#include "Day4Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_4
{

  const int part1_num_kernels = 8;
  const char part1_kernels[8][4][4] = {
      {{'X'},
       {'M'},
       {'A'},
       {'S'}},
      {{'S'},
       {'A'},
       {'M'},
       {'X'}},
      {{'X', 'M', 'A', 'S'}},
      {{'S', 'A', 'M', 'X'}},
      {{'X', '.', '.', '.'},
       {'.', 'M', '.', '.'},
       {'.', '.', 'A', '.'},
       {'.', '.', '.', 'S'}},
      {{'S', '.', '.', '.'},
       {'.', 'A', '.', '.'},
       {'.', '.', 'M', '.'},
       {'.', '.', '.', 'X'}},
      {{'.', '.', '.', 'X'},
       {'.', '.', 'M', '.'},
       {'.', 'A', '.', '.'},
       {'S', '.', '.', '.'}},
      {{'.', '.', '.', 'S'},
       {'.', '.', 'A', '.'},
       {'.', 'M', '.', '.'},
       {'X', '.', '.', '.'}},
  };

  const int part1_kernel_widths[] = {1, 1, 4, 4, 4, 4, 4, 4};
  const int part1_kernel_heights[] = {4, 4, 1, 1, 4, 4, 4, 4};

  const int part2_num_kernels = 4;
  const char part2_kernels[8][4][4] = {
      {{'M', '.', 'S'},
       {'.', 'A', '.'},
       {'M', '.', 'S'}},

      {{'M', '.', 'M'},
       {'.', 'A', '.'},
       {'S', '.', 'S'}},

      {{'S', '.', 'M'},
       {'.', 'A', '.'},
       {'S', '.', 'M'}},

      {{'S', '.', 'S'},
       {'.', 'A', '.'},
       {'M', '.', 'M'}}};

  const int part2_kernel_widths[] = {3, 3, 3, 3};
  const int part2_kernel_heights[] = {3, 3, 3, 3};

  void
  Day4Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int row_index = 0;
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        int len = strlen(line);
        if (line[len - 1] == '\n')
        {
          line[len - 1] = '\0';
          len--;
        }

        if (m_puzzle_size == 0)
          m_puzzle_size = len;

        strcpy(m_puzzle[row_index++], line);
      }
      fclose(fp);
    }
  }

  void Day4Solver::Run()
  {
    int words_found = 0;
    int xmas_found = 0;
    for (int i = 0; i < m_puzzle_size; i++)
    {
      for (int j = 0; j < m_puzzle_size; j++)
      {
        int count = Search(i, j, part1_num_kernels, part1_kernels, part1_kernel_widths, part1_kernel_heights);
        words_found += count;
        count = Search(i, j, part2_num_kernels, part2_kernels, part2_kernel_widths, part2_kernel_heights);
        xmas_found += count;
      }
    }
    SetPart1Answer(words_found);
    SetPart2Answer(xmas_found);
  }

  int Day4Solver::Search(int row, int col, const int num_kernels, const char kernels[8][4][4], const int *kernel_widths, const int *kernel_heights) const
  {
    int count = 0;
    for (int i = 0; i < num_kernels; i++)
    {
      int y1 = row;
      int y2 = row + kernel_heights[i];
      int x1 = col;
      int x2 = col + kernel_widths[i];

      bool found = true;
      if (y2 > m_puzzle_size || x2 > m_puzzle_size)
        found = false;

      for (int j = 0; j < kernel_heights[i] && found; j++)
      {
        for (int k = 0; k < kernel_widths[i] && found; k++)
        {
          if (kernels[i][j][k] != '.' && kernels[i][j][k] != m_puzzle[y1 + j][x1 + k])
            found = false;
        }
      }

      if (found)
        count++;
    }
    return count;
  }

} // namespace YEAR_2024::DAY_4
