add_library(AoC2024 Day1Solver.cpp
                     Day2Solver.cpp
                     Day3Solver.cpp
                     Day4Solver.cpp
                     Day5Solver.cpp
                     Day6Solver.cpp
                     Day7Solver.cpp
                     Day8Solver.cpp
                     Day9Solver.cpp
                     Day10Solver.cpp
                     Day11Solver.cpp
                     Day12Solver.cpp
                     Day13Solver.cpp
                    )

target_include_directories(AoC2024 PRIVATE ${CMAKE_SOURCE_DIR}/src)