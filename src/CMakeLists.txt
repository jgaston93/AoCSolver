add_subdirectory(2021)
add_subdirectory(2024)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(AoCSolverMain main.cpp SolverFactory.cpp AoCSolverCommon.cpp)

target_include_directories(AoCSolverMain PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(AoCSolverMain PRIVATE nlohmann_json::nlohmann_json AoC2021 AoC2024)