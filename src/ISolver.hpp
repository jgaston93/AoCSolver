#ifndef I_SOLVER_HPP
#define I_SOLVER_HPP

#include <cstdio>

class ISolver
{
public:
  virtual ~ISolver() = default;
  virtual void Initialize(const char *input_filename) = 0;
  virtual void Run() = 0;

  void PrintAnswer()
  {
    printf("Part 1 = %d\n", m_part1_answer);
    printf("Part 2 = %d\n", m_part2_answer);
  }

  void SetPart1Answer(int answer)
  {
    m_part1_answer = answer;
  }

  int GetPart1Answer() const
  {
    return m_part1_answer;
  }

  void SetPart2Answer(int answer)
  {
    m_part2_answer = answer;
  }

  int GetPart2Answer() const
  {
    return m_part2_answer;
  }

private:
  int m_part1_answer = 0;
  int m_part2_answer = 0;
};

#endif