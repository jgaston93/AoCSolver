#ifndef YEAR_2024_DAY_2_SOLVER_HPP
#define YEAR_2024_DAY_2_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_2
{
  const int MAX_REPORT_COUNT = 1000;
  const int MAX_REPORT_LENGTH = 32;
  class Day2Solver : public ISolver
  {
  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    int m_reports[MAX_REPORT_COUNT][MAX_REPORT_LENGTH] = {0};
    int m_velocities[MAX_REPORT_COUNT][MAX_REPORT_LENGTH] = {0};
    int m_accelerations[MAX_REPORT_COUNT][MAX_REPORT_LENGTH] = {0};
    int m_report_lengths[MAX_REPORT_COUNT] = {0};
    int m_report_count = 0;
  };
} // namespace YEAR_2024::DAY_2

#endif