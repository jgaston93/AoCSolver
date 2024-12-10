#ifndef YEAR_2024_DAY_9_SOLVER_HPP
#define YEAR_2024_DAY_9_SOLVER_HPP

#include "ISolver.hpp"

namespace YEAR_2024::DAY_9
{
  const int MAX_FILE_COUNT = 10000;
  const int MAX_POSITION = 94638;
  struct Node
  {
    unsigned int file_id = 0;
    Node *next_node = nullptr;
  };

  class Solver : public ISolver
  {

  public:
    void Initialize(const char *input_filename) final;
    void Run() final;

  private:
    unsigned int m_file_count = 0;
    unsigned int m_id[MAX_FILE_COUNT] = {0};
    unsigned int m_size[MAX_FILE_COUNT] = {0};
    unsigned int m_space[MAX_FILE_COUNT] = {0};
    unsigned int m_position[MAX_FILE_COUNT] = {0};
  };
} // namespace YEAR_2024::DAY_9

#endif