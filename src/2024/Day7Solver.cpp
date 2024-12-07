#include "Day7Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_7
{

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

        char *tok = strtok(line, ":");
        unsigned int test_value = 0;
        sscanf(tok, "%d", &test_value);

        m_test_values[m_num_equations] = test_value;

        tok = strtok(nullptr, " ");
        while (tok != nullptr)
        {
          unsigned int val = 0;
          sscanf(tok, "%d", &val);
          m_eq_values[m_num_equations][m_eq_value_counts[m_num_equations]++] = val;
          tok = strtok(nullptr, " ");
        }

        m_num_equations++;
      }
      fclose(fp);

      for (int i = 0; i < m_num_equations; i++)
      {
        printf("%u: ", m_test_values[i]);

        for (int j = 0; j < m_eq_value_counts[i]; j++)
        {
          printf("%u ", m_eq_values[i][j]);
        }
        printf("\n");
      }
    }
  }

  void Solver::Run()
  {
  }

} // namespace YEAR_2024::DAY_7
