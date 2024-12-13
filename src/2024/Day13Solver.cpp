#include "Day13Solver.hpp"

#include "AoCSolverCommon.hpp"

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
    for (int i = 0; i < m_num_machines; i++)
    {
      Press(0, 0, 0, 0, i);
    }
  }

  void Solver::Press(int x, int y, int num_a_presses, int num_b_presses, int machine_num)
  {
    if (x == m_prize_x[machine_num] && y == m_prize_y[machine_num])
    {
      printf("[%d] Prize Found: %d %d\n", machine_num, num_a_presses, num_b_presses);
    }
    else
    {
      int next_a_x = x + m_a_x[machine_num];
      int next_a_y = y + m_a_y[machine_num];
      if (next_a_x < m_prize_x[machine_num] && next_a_y < m_prize_y[machine_num] && num_a_presses < 100)
      {
        Press(next_a_x, next_a_y, num_a_presses + 1, num_b_presses, machine_num);
      }
      // else
      // {
      //   printf("No Path Found: num presses %d %d\n", num_a_presses, num_b_presses);
      //   printf("%d %d != %d %d\n", next_a_x, next_a_y, m_prize_x[machine_num], m_prize_y[machine_num]);
      // }

      int next_b_x = x + m_b_x[machine_num];
      int next_b_y = y + m_b_y[machine_num];
      if (next_b_x < m_prize_x[machine_num] && next_b_y < m_prize_y[machine_num] && num_b_presses < 100)
      {
        Press(next_b_x, next_b_y, num_a_presses, num_b_presses + 1, machine_num);
      }
      // else
      // {
      //   printf("No Path Found: num presses %d %d\n", num_a_presses, num_b_presses);
      //   printf("%d %d != %d %d\n", next_a_x, next_a_y, m_prize_x[machine_num], m_prize_y[machine_num]);
      // }
    }
  }

} // namespace YEAR_2024::DAY_13
