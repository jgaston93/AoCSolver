#include "Day2Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <math.h>
#include <string.h>

namespace YEAR_2024::DAY_2
{

  void Solver::Initialize(const char *input_filename)
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
        for (int j = 0; j < m_report_lengths[i]; j++)
        {
          // printf("%d\t", m_reports[i][j]);
        }
        // printf("\n");
        for (int j = 0; j < m_report_lengths[i] - 1; j++)
        {
          int delta = m_reports[i][j + 1] - m_reports[i][j];
          m_velocities[i][j] = delta;
          // printf("%d\t", delta);
        }
        // printf("\n");
        for (int j = 0; j < m_report_lengths[i] - 2; j++)
        {
          int delta_dot = m_velocities[i][j + 1] - m_velocities[i][j];
          m_accelerations[i][j] = delta_dot;
          // printf("%d\t", delta_dot);
        }
        // printf("\n");
        // printf("\n");
      }
    }
  }

  void Solver::Run()
  {
    int safe_report_count = 0;
    int dampened_report_count = 0;

    for (int i = 0; i < m_report_count; i++)
    {
      bool report_safe = true;

      int difference = m_velocities[i][0];
      if (difference == 0)
        report_safe = false;

      bool decreasing = difference < 0;
      for (int j = 0; j < m_report_lengths[i] - 1 && report_safe; j++)
      {
        difference = m_reports[i][j + 1] - m_reports[i][j];
        if (difference == 0 || (decreasing && difference > 0) || (!decreasing && difference < 0) || abs(difference) > 3)
          report_safe = false;
      }

      if (report_safe)
      {
        dampened_report_count++;
        safe_report_count++;
      }
      else
      {
        int index = 0;

        while (index < m_report_lengths[i] && !report_safe)
        {
          int new_report[MAX_REPORT_LENGTH] = {0};
          for (int j = 0; j < m_report_lengths[i]; j++)
          {
            if (j < index)
            {
              new_report[j] = m_reports[i][j];
            }
            else if (j > index)
            {
              new_report[j - 1] = m_reports[i][j];
            }
          }

          report_safe = true;

          difference = new_report[1] - new_report[0];
          if (difference == 0)
            report_safe = false;

          decreasing = difference < 0;
          for (int j = 0; j < m_report_lengths[i] - 2 && report_safe; j++)
          {
            difference = new_report[j + 1] - new_report[j];
            if (difference == 0 || (decreasing && difference > 0) || (!decreasing && difference < 0) || abs(difference) > 3)
              report_safe = false;
          }

          index++;
        }

        if (report_safe)
          dampened_report_count++;
      }
    }
    SetPart1Answer(safe_report_count);
    SetPart2Answer(dampened_report_count);
  }

} // namespace YEAR_2024::DAY_2
