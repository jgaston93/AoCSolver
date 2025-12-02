#include "SolverFactory.hpp"

#include "2021/Day1Solver.hpp"
#include "2021/Day2Solver.hpp"
#include "2021/Day3Solver.hpp"

#include "2024/Day1Solver.hpp"
#include "2024/Day2Solver.hpp"
#include "2024/Day3Solver.hpp"
#include "2024/Day4Solver.hpp"
#include "2024/Day5Solver.hpp"
#include "2024/Day6Solver.hpp"
#include "2024/Day7Solver.hpp"
#include "2024/Day8Solver.hpp"
#include "2024/Day9Solver.hpp"
#include "2024/Day10Solver.hpp"
#include "2024/Day11Solver.hpp"
#include "2024/Day12Solver.hpp"
#include "2024/Day13Solver.hpp"
#include "2024/Day14Solver.hpp"
#include "2024/Day15Solver.hpp"
#include "2024/Day16Solver.hpp"

#include "2025/Day1Solver.hpp"
#include "2025/Day2Solver.hpp"

#include <string.h>
#include <cstdio>

std::shared_ptr<ISolver> SolverFactory::createSolver(int year, const char *day)
{
  std::shared_ptr<ISolver> solver(nullptr);
  switch (year)
  {
  case 2021:
  {
    if (strcmp(day, "Day1Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_1::Day1Solver>());
    }
    else if (strcmp(day, "Day2Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_2::Day2Solver>());
    }
    else if (strcmp(day, "Day3Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_3::Day3Solver>());
    }
    else
    {
      printf("2021: Invalid Class Name %s\n", day);
    }
    break;
  }
  case 2024:
  {
    if (strcmp(day, "Day1") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_1::Solver>());
    }
    else if (strcmp(day, "Day2") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_2::Solver>());
    }
    else if (strcmp(day, "Day3") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_3::Solver>());
    }
    else if (strcmp(day, "Day4") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_4::Solver>());
    }
    else if (strcmp(day, "Day5") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_5::Solver>());
    }
    else if (strcmp(day, "Day6") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_6::Solver>());
    }
    else if (strcmp(day, "Day7") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_7::Solver>());
    }
    else if (strcmp(day, "Day8") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_8::Solver>());
    }
    else if (strcmp(day, "Day9") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_9::Solver>());
    }
    else if (strcmp(day, "Day10") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_10::Solver>());
    }
    else if (strcmp(day, "Day11") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_11::Solver>());
    }
    else if (strcmp(day, "Day12") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_12::Solver>());
    }
    else if (strcmp(day, "Day13") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_13::Solver>());
    }
    else if (strcmp(day, "Day14") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_14::Solver>());
    }
    else if (strcmp(day, "Day15") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_15::Solver>());
    }
    else if (strcmp(day, "Day16") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_16::Solver>());
    }
    else
    {
      printf("2024: Invalid Class Name %s\n", day);
    }
    break;
  }
  case 2025:
  {
    if (strcmp(day, "Day1") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2025::DAY_1::Solver>());
    }
    if (strcmp(day, "Day2") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2025::DAY_2::Solver>());
    }
    else
    {
      printf("2025: Invalid Class Name %s\n", day);
    }
    break;
  }
  default:
  {
    printf("Invalid Year %d\n", year);
  }
  }

  return solver;
}