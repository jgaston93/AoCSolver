#include "SolverFactory.hpp"

#include "2021/Day1Solver.hpp"
#include "2021/Day2Solver.hpp"
#include "2021/Day3Solver.hpp"

#include "2024/Day1Solver.hpp"
#include "2024/Day2Solver.hpp"
#include "2024/Day3Solver.hpp"
#include "2024/Day4Solver.hpp"

#include <string.h>
#include <cstdio>

std::shared_ptr<ISolver> SolverFactory::createSolver(int year, const char *solver_class)
{
  std::shared_ptr<ISolver> solver(nullptr);
  switch (year)
  {
  case 2021:
  {
    if (strcmp(solver_class, "Day1Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_1::Day1Solver>());
    }
    else if (strcmp(solver_class, "Day2Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_2::Day2Solver>());
    }
    else if (strcmp(solver_class, "Day3Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2021::DAY_3::Day3Solver>());
    }
    else
    {
      printf("Invalid Class Name\n");
    }
    break;
  }
  case 2024:
  {
    if (strcmp(solver_class, "Day1Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_1::Day1Solver>());
    }
    if (strcmp(solver_class, "Day2Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_2::Day2Solver>());
    }
    if (strcmp(solver_class, "Day3Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_3::Day3Solver>());
    }
    if (strcmp(solver_class, "Day4Solver") == 0)
    {
      solver = std::shared_ptr<ISolver>(std::make_shared<YEAR_2024::DAY_4::Day4Solver>());
    }
    else
    {
      printf("Invalid Class Name\n");
    }
    break;
  }
  default:
  {
    printf("Invalid Year\n");
  }
  }

  return solver;
}