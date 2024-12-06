#ifndef YEAR_2021_DAY_1_SOLVER_HPP
#define YEAR_2021_DAY_1_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2021::DAY_1
{
  const int MAX_SWEEP_COUNT = 2000;

  class Day1Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int ScanReports(int window_size) const;
    int m_report_count = 0;
    int m_sweep_reports[MAX_SWEEP_COUNT] = {0};
  };
} // namespace YEAR_2021::DAY_1

#endif