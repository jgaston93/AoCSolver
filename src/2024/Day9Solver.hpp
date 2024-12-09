#ifndef YEAR_2024_DAY_9_SOLVER_HPP
#define YEAR_2024_DAY_9_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_9
{
  const int MAX_FILE_COUNT = 10000;
  class Solver : public ISolver
  {

  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_files[MAX_FILE_COUNT] = {0};
  };
} // namespace YEAR_2024::DAY_9

#endif