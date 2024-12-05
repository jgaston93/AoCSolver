#include "Day5Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdio>
#include <cstring>

namespace YEAR_2024::DAY_5
{
  void
  Day5Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      int row_index = 0;
      fgets(line, sizeof(line), fp);
      AOC_SOLVER_COMMON::StripNewlines(line);
      while (strlen(line) > 1)
      {
        int a = 0;
        int b = 0;
        sscanf(line, "%d|%d\n", &a, &b);
        m_rules_list_1[m_num_rules] = a;
        m_rules_list_2[m_num_rules] = b;
        m_num_rules++;
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
      }

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);

        char *tok = strtok(line, ",");
        while (tok != nullptr)
        {
          int num = 0;
          sscanf(tok, "%d", &num);
          m_updates[m_num_updates][m_update_lengths[m_num_updates]++] = num;
          tok = strtok(nullptr, ",");
        }
        m_num_updates++;
      }
      fclose(fp);
    }
  }

  void Day5Solver::run()
  {
    int middle_page_number_sum = 0;
    int sorted_middle_page_number_sum = 0;
    for (int update_idx = 0; update_idx < m_num_updates; update_idx++)
    {
      int n = m_update_lengths[update_idx];
      int arr[MAX_NUM_PAGES] = {0};
      for (int i = 0; i < m_update_lengths[update_idx]; i++)
      {
        arr[i] = m_updates[update_idx][i];
      }

      for (int i = 1; i < n; ++i)
      {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && compare(arr[j], key))
        {
          arr[j + 1] = arr[j];
          j = j - 1;
        }
        arr[j + 1] = key;
      }

      bool sorted = true;
      for (int i = 0; i < m_update_lengths[update_idx] && sorted; i++)
      {
        if (arr[i] != m_updates[update_idx][i])
          sorted = false;
      }

      int mid_idx = (m_update_lengths[update_idx] / 2);
      int mid_val = arr[mid_idx];
      if (sorted)
        middle_page_number_sum += mid_val;
      else
        sorted_middle_page_number_sum += mid_val;
    }

    printf("Part 1 = %d\n", middle_page_number_sum);
    printf("Part 2 = %d\n", sorted_middle_page_number_sum);
  }

  bool Day5Solver::compare(int a, int b)
  {
    bool rule_found = false;
    bool greater_than = false;
    for (int i = 0; i < m_num_rules && !rule_found; i++)
    {
      if ((m_rules_list_1[i] == a && m_rules_list_2[i] == b) || (m_rules_list_1[i] == b && m_rules_list_2[i] == a))
      {
        if (m_rules_list_1[i] == a && m_rules_list_2[i] == b)
        {
          greater_than = false;
        }
        else if (m_rules_list_1[i] == b && m_rules_list_2[i] == a)
        {
          greater_than = true;
        }
        rule_found = true;
      }
    }
    if (!rule_found)
      printf("rule not found\n");
    return greater_than;
  }

} // namespace YEAR_2024::DAY_5
