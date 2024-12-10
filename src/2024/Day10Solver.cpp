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
        strcpy(m_map[counter++], line);
      }
      fclose(fp);

      for (int i = 0; i < m_map_size; i++)
      {
        for (int j = 0; j < m_map_size; j++)
        {
          if (m_map[i][j] == '0')
          {
            m_trailheads[m_num_trailheads]->height = 0;
            m_trailheads[m_num_trailheads]->x = j;
            m_trailheads[m_num_trailheads]->y = i;
            m_num_trailheads++;
          }
        }
      }
    }
  }

  void Solver::Run()
  {
  }

} // namespace YEAR_2024::DAY_10
