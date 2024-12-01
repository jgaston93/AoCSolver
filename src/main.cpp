#include "SolverFactory.hpp"

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

const int MAX_STRING_LENGTH = 256;

int main(int argc, char **argv)
{
  // Parse command line arguments
  cxxopts::Options options("AoCSolver",
                           "C++ project for solving Advent of Code problems");
  options.add_options()("c,config", "Configuration file", cxxopts::value<std::string>())("s,sample_input", "Use sample input", cxxopts::value<bool>()->default_value("false"));

  auto arguments = options.parse(argc, argv);

  // Parse configuration data
  const char *config_file_str = arguments["config"].as<std::string>().data();
  std::ifstream f(config_file_str);
  auto configuration_data = nlohmann::json::parse(f);

  // Read configuration data
  int year = configuration_data["year"];      // year of solver
  char solver_class[MAX_STRING_LENGTH] = {0}; // day of solver
  strcpy(solver_class, configuration_data["solver_class"].get<std::string>().data());
  char input_file[MAX_STRING_LENGTH] = {0}; // input file for solver

  // Determine if using actual or sample input
  if (arguments["sample_input"].as<bool>())
  {
    strcpy(input_file, configuration_data["sample_input_file"].get<std::string>().data());
  }
  else
  {
    strcpy(input_file, configuration_data["input_file"].get<std::string>().data());
  }

  // Initialize and run solver
  std::shared_ptr<ISolver> solver = SolverFactory::createSolver(year, solver_class);

  solver->initialize(input_file);
  solver->run();

  return 0;
}