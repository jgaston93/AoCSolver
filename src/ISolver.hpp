#ifndef I_SOLVER_HPP
#define I_SOLVER_HPP

class ISolver
{
public:
  virtual ~ISolver() = default;
  virtual void initialize(const char *input_filename) = 0;
  virtual void run() const = 0;
};

#endif