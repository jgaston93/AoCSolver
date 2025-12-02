#include "Day2Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdlib>
#include <string.h>

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
    int part1_answer = 0;
    int part2_answer = 0;

    for (int range_index = 0; range_index < num_ranges; range_index++)
    {
      for (int range_count = 0; range_count < ranges[range_index].length; range_count++)
      { // printf("%s\n", ranges[range_index].start);
        int str_len = strlen(ranges[range_index].start);
        for (int sub_str_len = 1; sub_str_len <= (str_len / 2); sub_str_len++)
        {
          char sub_str[12];
          strcpy(sub_str, ranges[range_index].start);
          sub_str[sub_str_len] = '\0';
          // printf("%s\n", sub_str);

          int idx = sub_str_len;
          bool is_equal = true;
          while (idx < str_len && is_equal)
          {
            // printf("Comparing: '%s' and '%s'\n", sub_str, ranges[range_index].start + idx);
            if (strncmp(sub_str, ranges[range_index].start + idx, sub_str_len) != 0)
            {
              is_equal = false;
            }
            idx += sub_str_len;
          }

          if (is_equal)
          {
            part1_answer++;
          }
        }
        // printf("\n");
      }
    }

    SetPart1Answer(part1_answer);
    SetPart2Answer(part2_answer);
  }
} // namespace YEAR_2024::DAY_2
