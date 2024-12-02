#include "Day2Solver.hpp"

#include "AOCSolverCommon.hpp"

#include <cstdio>
#include <math.h>
#include <string.h>

namespace YEAR_2024::DAY_2
{

  void Day2Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      m_report_count = 0;

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        const char *report_string = strtok(line, " ");

        int report_length = 0;

        while (report_string != nullptr)
        {
          int report = 0;
          sscanf(report_string, "%d", &report);

          m_reports[m_report_count][report_length++] = report;

          report_string = strtok(nullptr, " ");
        }
        m_report_lengths[m_report_count++] = report_length;
      }
      fclose(fp);

      for (int i = 0; i < m_report_count; i++)
      {
        for (int j = 0; j < m_report_lengths[i] - 1; j++)
        {
          printf("%d ", m_reports[i][j] - m_reports[i][j + 1]);
        }
        printf("\n");
      }
    }
  }

  void Day2Solver::run() const
  {
    int safe_report_count = 0;

    for (int i = 0; i < m_report_count; i++)
    {
      bool report_safe = true;
      int difference = m_reports[i][0] - m_reports[i][1];
      if (difference == 0)
        report_safe = false;
      bool decreasing = difference > 0;
      for (int j = 0; j < m_report_lengths[i] - 1 && report_safe; j++)
      {
        difference = m_reports[i][j] - m_reports[i][j + 1];
        if (difference == 0 || (decreasing && difference < 0) || (!decreasing && difference > 0) || abs(difference) > 3)
          report_safe = false;
      }

      if (report_safe)
        safe_report_count++;
    }
    printf("Part 1 = %d\n", safe_report_count);
    // printf("Part 2 = %d\n", similarity_score);
  }

} // namespace YEAR_2024::DAY_1
