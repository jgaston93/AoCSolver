add_library(AoC2025 Day1Solver.cpp
                    Day2Solver.cpp
                    Day3Solver.cpp
                    Day4Solver.cpp)

target_include_directories(AoC2025 PRIVATE ${CMAKE_SOURCE_DIR}/src)