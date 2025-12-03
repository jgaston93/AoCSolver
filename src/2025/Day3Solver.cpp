#include "Day3Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <string.h>
#include <cstdlib>

bool isMaskFull(char *mask)
{
  int mask_len = strlen(mask);
  bool mask_full = true;
  int idx = 0;
  while (idx < mask_len && mask_full)
  {
    if (mask[idx] == '0')
    {
      mask_full = false;
    }
    idx++;
  }
  return mask_full;
}

void incrementMask(char *mask)
{
  int idx = 0;
  int carry_over = 1;
  while (carry_over > 0)
  {
    mask[idx] += carry_over;
    carry_over--;
    if (mask[idx] > '1')
    {
      mask[idx] = '0';
      idx++;
      carry_over++;
    }

    if (carry_over > 0 && mask[idx] == '\0')
    {
      mask[idx] = '0';
      mask[idx + 1] = '\0';
    }
  }
}

bool isMaskValid(char *mask, int count)
{
  int c = 0;
  int len = strlen(mask);
  for (int i = 0; i <= len; i++)
  {
    if (mask[i] == '1')
    {
      c++;
    }
  }
  return c == count;
}

namespace YEAR_2025::DAY_3
{
  Solver::Solver() : m_num_banks(0), m_bank_size(0)
  {
    for (int i = 0; i < MAX_ROW; i++)
    {
      memset(m_battery_banks[i], '\0', sizeof m_battery_banks[i]);
    }
  }

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        AOC_SOLVER_COMMON::StripNewlines(line);
        strcpy(m_battery_banks[m_num_banks++], line);
        m_bank_size = strlen(line);
      }

      fclose(fp);
    }
  }

  void Solver::Run()
  {
    unsigned long long int part1_answer = 0;
    unsigned long long int part2_answer = 0;

    for (int bank_index = 0; bank_index < m_num_banks; bank_index++)
    {
      int max_joltage = 0;

      char mask[MAX_COL];
      memset(mask, '0', m_bank_size);
      mask[m_bank_size] = '\0';

      while (!isMaskFull(mask))
      {
        if (isMaskValid(mask, 2))
        {
          printf("%s\n", mask);
        }
        incrementMask(mask);
      }

      //   for (int batt_1 = 0; batt_1 < m_bank_size - 1; batt_1++)
      //   {
      //     for (int batt_2 = batt_1 + 1; batt_2 < m_bank_size; batt_2++)
      //     {
      //       char joltage_str[3];
      //       joltage_str[0] = m_battery_banks[bank_index][batt_1];
      //       joltage_str[1] = m_battery_banks[bank_index][batt_2];
      //       joltage_str[2] = '\0';

      //       int joltage = atoi(joltage_str);
      //       if (joltage > max_joltage)
      //       {
      //         max_joltage = joltage;
      //       }
      //     }
      //   }
      //   part1_answer += max_joltage;
    }

    // printf("part1_answer=%llu\n", part1_answer);

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }

  void Solver::PrintAnswer() const
  {
  }
} // namespace YEAR_2024::DAY_3
