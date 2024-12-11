#ifndef YEAR_2024_DAY_11_SOLVER_HPP
#define YEAR_2024_DAY_11_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_11
{
  using uint64_t = unsigned long long;
  const int BIT64_BASE10_CHARS = 20;

  struct Stone
  {
    uint64_t value = 0;
    Stone *next_stone = nullptr;
  };

  class Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    Stone *m_first_stone = nullptr;
  };
} // namespace YEAR_2024::DAY_11

#endif