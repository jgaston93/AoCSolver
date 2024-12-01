add_library(AoC2021 Day1Solver.cpp Day2Solver.cpp Day3Solver.cpp)

target_include_directories(AoC2021 PRIVATE ${CMAKE_SOURCE_DIR}/src)