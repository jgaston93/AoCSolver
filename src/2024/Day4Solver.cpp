#include "Day4Solver.hpp"

#include "AOCSolverCommon.hpp"

#include <cstdio>
#include <cstring>

namespace YEAR_2024::DAY_4
{

  int num_filters = 8;
  char filters[8][4][4] = {{{'x'},
                            {'m'},
                            {'a'},
                            {'s'}},
                           {{'s'},
                            {'a'},
                            {'m'},
                            {'x'}},
                           {{'x', 'm', 'a', 's'}},
                           {{'s', 'a', 'm', 'x'}},
                           {{'x', '.', '.', '.'},
                            {'.', 'm', '.', '.'},
                            {'.', '.', 'a', '.'},
                            {'.', '.', '.', 's'}},
                           {{'s', '.', '.', '.'},
                            {'.', 'a', '.', '.'},
                            {'.', '.', 'm', '.'},
                            {'.', '.', '.', 'x'}},
                           {{'.', '.', '.', 'x'},
                            {'.', '.', 'm', '.'},
                            {'.', 'a', '.', '.'},
                            {'s', '.', '.', '.'}},
                           {{'.', '.', '.', 's'},
                            {'.', '.', 'a', '.'},
                            {'.', 'm', '.', '.'},
                            {'x', '.', '.', '.'}}};

  int filter_widths[] = {1, 1, 4, 4, 4, 4, 4, 4};
  int filter_heights[] = {4, 4, 1, 1, 4, 4, 4, 4};

  void
  Day4Solver::initialize(const char *input_filename)
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

  void Day4Solver::run() const
  {
    const char keyword[] = "xmas";
    for (int i = 0; i < m_puzzle_size; i++)
    {
      for (int j = 0; j < m_puzzle_size; j++)
      {
        search(i, j, keyword);
      }
    }
    // printf("Part 1 = %d\n", safe_report_count);
    // printf("Part 2 = %d\n", dampened_report_count);
  }

  void Day4Solver::search(int row, int col, const char *word) const
  {
    int directions = 8;
    bool word_found[] = {false, false, false, false, false, false, false, false};

    int word_len = strlen(word);
    int max_window_size = word_len * 2 - 1;

    for (int i = 0; i < word_len; i++)
    {
    }
  }

} // namespace YEAR_2024::DAY_4
