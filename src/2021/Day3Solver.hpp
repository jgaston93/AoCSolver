#ifndef YEAR_2021_DAY_3_SOLVER_HPP
#define YEAR_2021_DAY_3_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2021::DAY_3
{
  const int MAX_DIAGNOSTIC_COUNT = 1000;
  const int MAX_RECORD_WIDTH = 32;

  class Day3Solver : public ISolver
  {
  public:
    void initialize(const char *input_filename) final;
    void run() final;

  private:
    int m_record_count = 0;
    int m_record_width = 0;
    unsigned int m_records[MAX_DIAGNOSTIC_COUNT];
  };
} // namespace YEAR_2021::DAY_3

#endif