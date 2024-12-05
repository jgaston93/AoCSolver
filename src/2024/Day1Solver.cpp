#include "Day1Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstdio>
#include <math.h>

namespace YEAR_2024::DAY_1
{

  void Day1Solver::initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};

      while (!feof(fp))
      {
        fgets(line, sizeof(line), fp);
        int location_id_1 = 0;
        int location_id_2 = 0;
        sscanf(line, "%d   %d", &location_id_1, &location_id_2);
        InsertLocationId(location_id_1, m_location_id_count_1, m_location_id_list_1);
        InsertLocationId(location_id_2, m_location_id_count_2, m_location_id_list_2);
      }
      fclose(fp);

      int current_id = m_location_id_list_2[0];
      m_id_value_list[m_id_count] = current_id;

      for (int i = 0; i < m_location_id_count_2; i++)
      {
        if (current_id != m_location_id_list_2[i])
        {
          m_id_count++;
          current_id = m_location_id_list_2[i];
          m_id_value_list[m_id_count] = current_id;
          m_id_count_list[m_id_count] = 1;
        }
        else
        {
          m_id_count_list[m_id_count]++;
        }
      }
      m_id_count++;
    }
  }

  void Day1Solver::run()
  {
    int difference_score = 0;
    int similarity_score = 0;
    CalculateScores(difference_score, similarity_score);
    printf("Part 1 = %d\n", difference_score);
    printf("Part 2 = %d\n", similarity_score);
  }

  void Day1Solver::InsertLocationId(int location_id, int &count, int *location_id_list) const
  {
    int insert_index = 0;

    while (insert_index < count && location_id_list[insert_index] < location_id)
      insert_index++;

    while (insert_index <= count)
    {
      int id = location_id_list[insert_index];
      location_id_list[insert_index] = location_id;
      location_id = id;
      insert_index++;
    }
    count++;
  }

  void Day1Solver::CalculateScores(int &difference_score, int &similarity_score) const
  {
    difference_score = 0;
    similarity_score = 0;
    int multiplier = 0;
    int index = 0;
    for (int i = 0; i < m_location_id_count_1; i++)
    {
      int distance = abs(m_location_id_list_1[i] - m_location_id_list_2[i]);
      difference_score += distance;

      if (m_location_id_list_1[i] != m_id_value_list[index])
      {
        multiplier = 0;
        while (m_location_id_list_1[i] > m_id_value_list[index])
          index++;
      }

      if (m_location_id_list_1[i] == m_id_value_list[index])
        multiplier = m_id_count_list[index];

      similarity_score += m_location_id_list_1[i] * multiplier;
    }
  }
} // namespace YEAR_2024::DAY_1
