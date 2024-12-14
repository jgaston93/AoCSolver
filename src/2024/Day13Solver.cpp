#include "Day13Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <queue>

namespace YEAR_2024::DAY_13
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      while (!feof(fp))
      {
        int x = 0;
        int y = 0;
        fgets(line, sizeof(line), fp);
        sscanf(line, "Button A: X+%d, Y+%d", &x, &y);
        m_a_x[m_num_machines] = x;
        m_a_y[m_num_machines] = y;

        fgets(line, sizeof(line), fp);
        sscanf(line, "Button B: X+%d, Y+%d", &x, &y);
        m_b_x[m_num_machines] = x;
        m_b_y[m_num_machines] = y;

        fgets(line, sizeof(line), fp);
        sscanf(line, "Prize: X=%d, Y=%d", &x, &y);
        m_prize_x[m_num_machines] = x;
        m_prize_y[m_num_machines] = y;

        fgets(line, sizeof(line), fp);
        m_num_machines++;
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int num_tokens = 0;
    for (int machine_num = 0; machine_num < m_num_machines; machine_num++)
    {
      bool solution_found = false;
      for (int i = 0; i < 100 && !solution_found; i++)
      {
        for (int j = 0; j < 100 && !solution_found; j++)
        {
          int x = (m_a_x[machine_num] * i) + (m_b_x[machine_num] * j);
          int y = (m_a_y[machine_num] * i) + (m_b_y[machine_num] * j);
          if (x == m_prize_x[machine_num] && y == m_prize_y[machine_num])
          {
            solution_found = true;
            num_tokens += (i * 3) + j;
          }
        }
      }
    }
    SetPart1Answer(num_tokens);
  }

} // namespace YEAR_2024::DAY_13
