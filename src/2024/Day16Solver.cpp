#include "Day16Solver.hpp"

#include <cstring>

using namespace AOC_SOLVER_COMMON;

namespace YEAR_2024::DAY_16
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int row = 0;
      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        StripNewlines(line);
        if (m_map_size == 0)
        {
          m_map_size = strlen(line);
        }
        strcpy(m_map[row++], line);
      }
      fclose(fp);

      for (int i = 0; i < m_map_size; i++)
      {
        printf("%s\n", m_map[i]);
      }
    }
  }

  void Solver::Run()
  {
  }

  void Move(int x, int y, Direction dir, int score)
  {
    }

} // namespace YEAR_2024::DAY_16
