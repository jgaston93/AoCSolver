#ifndef YEAR_2025_DAY_1_SOLVER_HPP
#define YEAR_2025_DAY_1_SOLVER_HPP

#include "ISolver.hpp"

#include "AoCSolverCommon.hpp"
namespace YEAR_2025::DAY_1
{
  const int MAX_ROTATIONS = 5000;
  struct Rotation
  {
    AOC_SOLVER_COMMON::Direction direction;
    int count;
    Rotation() : direction(AOC_SOLVER_COMMON::Direction::UP), count(0)
    {
    }
  };
  class Solver : public ISolver
  {
  public:
    Solver();
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    Rotation rotations[MAX_ROTATIONS];
    int num_rotations;
  };
} // namespace YEAR_2024::DAY_1

#endif