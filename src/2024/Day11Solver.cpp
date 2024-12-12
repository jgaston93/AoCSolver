#include "Day11Solver.hpp"

#include "AoCSolverCommon.hpp"

#include <cstring>

namespace YEAR_2024::DAY_11
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      fgets(line, sizeof(line), fp);

      Stone *previous_stone = nullptr;

      char *tok = strtok(line, " ");
      while (tok != nullptr)
      {
        Stone *stone = new Stone();
        sscanf(tok, "%llu", &(stone->value));

        if (m_first_stone == nullptr)
          m_first_stone = stone;

        if (previous_stone != nullptr)
          previous_stone->next_stone = stone;

        previous_stone = stone;
        tok = strtok(nullptr, " ");
      }
      fclose(fp);
    }
  }

  void Solver::Run()
  {
    int total_blink_count = 25;
    int blink_count = 0;

    while (blink_count < total_blink_count)
    {
      Stone *s = m_first_stone;
      while (s != nullptr)
      {
        bool multiply = false;
        if (s->value == 0)
          s->value = 1;
        else
        {
          char v_str[BIT64_BASE10_CHARS + 1];
          sprintf(v_str, "%llu", s->value);
          int len = strlen(v_str);
          if ((len % 2) == 0)
          {
            uint64_t a = 0;
            uint64_t b = 0;

            sscanf(&(v_str[len / 2]), "%llu", &b);
            v_str[len / 2] = '\0';
            sscanf(v_str, "%llu", &a);
            Stone *remaining_stones = s->next_stone;
            s->value = a;
            s->next_stone = new Stone();
            s = s->next_stone;
            s->value = b;
            s->next_stone = remaining_stones;
          }
          else
            multiply = true;

          if (multiply)
            s->value *= 2024;
        }
        s = s->next_stone;
      }
      blink_count++;
    }

    int stone_count_25 = 0;
    Stone *s = m_first_stone;
    while (s != nullptr)
    {
      stone_count_25++;
      s = s->next_stone;
    }
    SetPart1Answer(stone_count_25);
  }

} // namespace YEAR_2024::DAY_11
