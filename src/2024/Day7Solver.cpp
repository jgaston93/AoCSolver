#include "Day7Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>
#include <math.h>

namespace YEAR_2024::DAY_7
{
  uint64_t Concatenate(uint64_t a, uint64_t b)
  {
    char a_str[41] = {0};
    char b_str[21] = {0};

    sprintf(a_str, "%llu", a);
    sprintf(b_str, "%llu", b);

    strcat(a_str, b_str);

    uint64_t result = 0;
    sscanf(a_str, "%llu", &result);

    return result;
  }

  bool Evaluate(uint64_t test_value, uint64_t result, int operator_index, int num_terms, const uint64_t *terms, Operator operation)
  {
    bool solution_found = false;

    if (operation == Operator::ADDITION)
    {
      result += terms[operator_index];
    }
    else if (operation == Operator::MULTIPLICATION)
    {
      result *= terms[operator_index];
    }

    int remaining_operations = (num_terms - 1) - (operator_index + 1);

    if (remaining_operations == 0 && result == test_value)
      solution_found = true;
    else if (remaining_operations > 0 && result < test_value)
    {
      bool addition_solution_found = Evaluate(test_value, result, operator_index + 1, num_terms, terms, Operator::ADDITION);
      bool multiplication_solution_found = Evaluate(test_value, result, operator_index + 1, num_terms, terms, Operator::MULTIPLICATION);

      if (addition_solution_found || multiplication_solution_found)
        solution_found = true;
    }

    return solution_found;
  }

  uint64_t Evaluate(int num_terms, const uint64_t *terms, const Operator *operators)
  {
    uint64_t t[MAX_NUM_TERMS] = {0};
    int num_t = 0;
    int concat_count = 0;
    for (int i = 0; i < num_terms - 1; i++)
    {
      if (operators[i] == Operator::CONCATENATION)
      {
        concat_count++;
        uint64_t term = Concatenate(terms[i], terms[i + 1]);
        t[num_t++] = term;
        i++;
      }
      else
      {
        t[num_t++] = terms[i];
      }
    }

    if (operators[num_terms - 2] != Operator::CONCATENATION)
    {
      t[num_t++] = terms[num_terms - 1];
    }

    uint64_t result = t[0];
    int op_index = 0;
    for (int i = 1; i < num_t; i++)
    {
      while (operators[op_index] == Operator::CONCATENATION)
        op_index++;

      if (operators[op_index] == Operator::ADDITION)
      {
        result += t[i];
      }
      else if (operators[op_index] == Operator::MULTIPLICATION)
      {
        result *= t[i];
      }
    }
    return result;
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

        char *tok = strtok(line, ":");
        uint64_t test_value = 0;
        sscanf(tok, "%llu", &test_value);

        m_test_values[m_num_equations] = test_value;

        tok = strtok(nullptr, " ");
        while (tok != nullptr)
        {
          uint64_t val = 0;
          sscanf(tok, "%llu", &val);
          m_terms[m_num_equations][m_num_terms[m_num_equations]++] = val;
          tok = strtok(nullptr, " ");
        }

        m_num_equations++;
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    uint64_t test_value_sum = 0;
    for (int i = 0; i < m_num_equations; i++)
    {
      bool addition_equation_solved = Evaluate(m_test_values[i], m_terms[i][0], 1, m_num_terms[i], &m_terms[i][0], Operator::ADDITION);
      bool multiplication_equation_solved = Evaluate(m_test_values[i], m_terms[i][0], 1, m_num_terms[i], &m_terms[i][0], Operator::MULTIPLICATION);

      if (addition_equation_solved || multiplication_equation_solved)
        test_value_sum += m_test_values[i];
      else
      {
        printf("%llu: ", m_test_values[i]);
        for (int j = 0; j < m_num_terms[i]; j++)
        {
          printf("%llu ", m_terms[i][j]);
        }
        printf("\n");
      }
    }
    printf("Reuslt = %llu\n", test_value_sum);
  }

} // namespace YEAR_2024::DAY_7
