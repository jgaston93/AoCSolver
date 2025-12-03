#include "Day2Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdlib>
#include <string.h>

void reverse_str(char *str)
{
  int start = 0;
  int end = strlen(str) - 1;

  while (start < end)
  {
    char temp = str[end];
    str[end] = str[start];
    str[start] = temp;

    start++;
    end--;
  }
}

namespace YEAR_2025::DAY_2
{
  Solver::Solver() : num_ranges(0)
  {
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
      }

      char *token = strtok(line, "-");
      while (token != NULL)
      {
        ProductIDRange range;
        strcpy(range.start, token);
        reverse_str(range.start);

        int range_start = atoi(token);

        token = strtok(NULL, ",");
        int range_end = atoi(token);

        range.length = range_end - range_start;
        ranges[num_ranges++] = range;

        token = strtok(NULL, "-");
      }

      fclose(fp);
    }
  }

  void Solver::Run()
  {
    unsigned long long int part1_answer = 0;
    unsigned long long int part2_answer = 0;

    for (int range_index = 0; range_index < num_ranges; range_index++)
    {
      for (int range_count = 0; range_count < ranges[range_index].length + 1; range_count++)
      {
        // Part 1
        {
          int str_len = strlen(ranges[range_index].start);
          if (str_len % 2 == 0)
          {
            int sub_str_len = str_len / 2;
            char sub_str[MAX_NUM_CHARACTERS];
            strncpy(sub_str, ranges[range_index].start, sub_str_len);
            sub_str[sub_str_len] = '\0';
            if (strcmp(sub_str, &ranges[range_index].start[sub_str_len]) == 0)
            {
              char str[MAX_NUM_CHARACTERS];
              strcpy(str, ranges[range_index].start);
              reverse_str(str);
              unsigned long long int value = std::strtoull(str, NULL, 10);
              part1_answer += value;
            }
          }
        }
        // Part 2
        {
          bool pattern_found = false;
          int str_len = strlen(ranges[range_index].start);
          for (int sub_str_len = 1; sub_str_len <= (str_len / 2) && !pattern_found; sub_str_len++)
          {
            char sub_str[MAX_NUM_CHARACTERS];
            strcpy(sub_str, ranges[range_index].start);
            sub_str[sub_str_len] = '\0';

            int idx = sub_str_len;
            bool is_equal = true;
            while (idx < str_len && is_equal)
            {
              if (strncmp(sub_str, ranges[range_index].start + idx, sub_str_len) != 0)
              {
                is_equal = false;
              }
              idx += sub_str_len;
            }

            if (is_equal)
            {
              char str[MAX_NUM_CHARACTERS];
              strcpy(str, ranges[range_index].start);
              reverse_str(str);
              unsigned long long int value = std::strtoull(str, NULL, 10);
              part2_answer += value;
              pattern_found = true;
            }
          }
        }

        int carry_over = 1;
        int index = 0;
        while (carry_over > 0)
        {
          ranges[range_index].start[index]++;
          carry_over = 0;
          if (ranges[range_index].start[index] > '9')
          {
            ranges[range_index].start[index] = '0';
            index++;
            carry_over = 1;
          }

          if (carry_over > 0 && ranges[range_index].start[index] == '\0')
          {
            ranges[range_index].start[index] = '0';
            ranges[range_index].start[index + 1] = '\0';
          }
        }
      }
    }

    printf("part1_answer=%llu\n", part1_answer);
    printf("part2_answer=%llu\n", part2_answer);

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }

  void Solver::PrintAnswer() const
  {
  }
} // namespace YEAR_2024::DAY_2
