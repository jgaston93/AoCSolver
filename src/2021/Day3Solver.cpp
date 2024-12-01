#include "Day3Solver.hpp"

#include "AOCSolverCommon.hpp"

#include <cstdio>
#include <string.h>
#include <math.h>

namespace YEAR_2021::DAY_3
{

  void removeAtIndex(unsigned int *arr, int size, int index)
  {
    for (int i = index; i < size - 1; i++)
    {
      int swap = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = swap;
    }
    arr[size - 1] = 0;
  }

  void getBitCounts(const unsigned int *records, int record_count, int record_width, int *counts)
  {
    for (int i = 0; i < record_count; i++)
    {
      for (int j = 0; j < record_width; j++)
      {
        counts[(record_width - 1) - j] += 0x00000001 & (records[i] >> j);
      }
    }
  }

  void Day3Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      while (!feof(fp))
      {
        char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
        fgets(line, sizeof(line), fp);

        int length = strlen(line);

        if (line[length - 1] == '\n')
        {
          line[length - 1] = '\0';
          length--;
        }

        if (m_record_width == 0)
        {
          m_record_width = length;
        }

        unsigned int record = 0;
        unsigned int exponent = 0;

        for (int i = length - 1; i >= 0; i--)
        {
          unsigned int value = 0;
          if (line[i] == '1')
          {
            value = 1;
          }

          record += (unsigned int)(pow(2, exponent) * value);
          exponent++;
        }

        m_records[m_record_count++] = record;
      }
      fclose(fp);
    }
  }

  void Day3Solver::run() const
  {
    int record_counts[MAX_RECORD_WIDTH] = {0};

    // Count the 1 bits in each column
    getBitCounts(m_records, m_record_count, m_record_width, record_counts);

    unsigned int gamma_rate = 0;
    unsigned int exponent = m_record_width - 1;

    unsigned int oxygen_generator_rating_count = 0;
    unsigned int co2_scrubber_rating_count = 0;
    unsigned int oxygen_generator_rating_list[MAX_RECORD_WIDTH] = {0};
    unsigned int co2_scrubber_rating_list[MAX_RECORD_WIDTH] = {0};

    for (int i = 0; i < m_record_width; i++)
    {
      unsigned int value = 0;

      if (record_counts[i] > (m_record_count - record_counts[i]))
      {
        value = 1;
      }
      gamma_rate += (unsigned int)(pow(2, exponent) * value);

      if (oxygen_generator_rating_count == 0 && co2_scrubber_rating_count == 0)
      {
        for (int j = 0; j < m_record_count; j++)
        {
          if ((record_counts[i] >= (m_record_count - record_counts[i])) && (((m_records[j] >> exponent) & 0x01) == 1))
          {
            oxygen_generator_rating_list[oxygen_generator_rating_count++] = m_records[j];
          }
          if ((record_counts[i] >= (m_record_count - record_counts[i])) && (((m_records[j] >> exponent) & 0x01) == 0))
          {
            co2_scrubber_rating_list[co2_scrubber_rating_count++] = m_records[j];
          }
        }
      }
      else
      {
        if (oxygen_generator_rating_count > 1)
        {
          int current_count = oxygen_generator_rating_count;
          int subset_record_counts[MAX_RECORD_WIDTH] = {0};
          getBitCounts(oxygen_generator_rating_list, oxygen_generator_rating_count, m_record_width, subset_record_counts);
          for (int j = 0; j < oxygen_generator_rating_count; j++)
          {
            if (((subset_record_counts[i] >= (current_count - subset_record_counts[i])) && (((oxygen_generator_rating_list[j] >> exponent) & 0x01) != 1)) ||
                (((current_count - subset_record_counts[i]) > subset_record_counts[i]) && (((oxygen_generator_rating_list[j] >> exponent) & 0x01) != 0)))
            {
              removeAtIndex(oxygen_generator_rating_list, oxygen_generator_rating_count, j);
              oxygen_generator_rating_count--;
              j--;
            }
          }
        }
        if (co2_scrubber_rating_count > 1)
        {
          int current_count = co2_scrubber_rating_count;
          int subset_record_counts[MAX_RECORD_WIDTH] = {0};
          getBitCounts(co2_scrubber_rating_list, co2_scrubber_rating_count, m_record_width, subset_record_counts);
          for (int j = 0; j < co2_scrubber_rating_count; j++)
          {
            if (((subset_record_counts[i] >= (current_count - subset_record_counts[i])) && (((co2_scrubber_rating_list[j] >> exponent) & 0x01) != 0)) ||
                (((current_count - subset_record_counts[i]) > subset_record_counts[i]) && (((co2_scrubber_rating_list[j] >> exponent) & 0x01) != 1)))
            {
              removeAtIndex(co2_scrubber_rating_list, co2_scrubber_rating_count, j);
              co2_scrubber_rating_count--;
              j--;
            }
          }
        }
      }
      exponent--;
    }

    // Determine epsilon based on gamma
    unsigned int epsilon_mask = 0;
    for (int i = 0; i < m_record_width; i++)
    {
      epsilon_mask += pow(2, i);
    }
    unsigned int epsilon_rate = (~gamma_rate) & epsilon_mask;

    printf("Part 1 = %d\n", gamma_rate * epsilon_rate);
    printf("Part 2 = %d\n", oxygen_generator_rating_list[0] * co2_scrubber_rating_list[0]);
  }
} // namespace YEAR_2021::DAY_3 // namespace YEAR_2021