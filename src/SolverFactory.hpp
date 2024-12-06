#ifndef SOLVER_FACTORY_HPP
#define SOLVER_FACTORY_HPP

#include "ISolver.hpp"

#include <memory>

class SolverFactory
{
public:
  static std::shared_ptr<ISolver> createSolver(int year, const char *day);
};

#endif