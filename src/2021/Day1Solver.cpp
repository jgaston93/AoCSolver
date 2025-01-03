#include "Day1Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdio>

namespace YEAR_2021::DAY_1
{

  int sum_reports(const int *reports, int window_size)
  {
    int sum = 0;
    for (int i = 0; i < window_size; i++)
    {
      sum += reports[i];
    }
    return sum;
  }

  void Day1Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        int report = 0;
        sscanf(line, "%d", &report);
        m_sweep_reports[m_report_count++] = report;
      }
      fclose(fp);
    }
  }

  void Day1Solver::Run()
  {
    int window_size = 1;
    int part_1_final_report = ScanReports(window_size);
    window_size = 3;
    int part_2_final_report = ScanReports(window_size);

    printf("Part 1 = %d\n", part_1_final_report);
    printf("Part 2 = %d\n", part_2_final_report);
  }

  int Day1Solver::ScanReports(int window_size) const
  {
    int previous_report = sum_reports(&(m_sweep_reports[0]), window_size);
    int increase_count = 0;
    bool end_reached = false;
    for (int i = 0; i < m_report_count && !end_reached; i++)
    {
      if (i + window_size > m_report_count)
      {
        end_reached = true;
      }

      if (!end_reached)
      {
        int sum = sum_reports(&(m_sweep_reports[i]), window_size);
        if (sum > previous_report)
        {
          increase_count++;
        }
        previous_report = sum;
      }
    }
    return increase_count;
  }
} // namespace YEAR_2021::DAY_1
