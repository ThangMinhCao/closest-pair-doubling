cmake_minimum_required(VERSION 3.16)
project(ClosestPairDoubling)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(utils)

set(MAIN_HEADERS include/closest_pair_doubling.h include/kth_smallest.h include/point.h
        include/point_list.h include/random_generator.h)
set(MAIN_SOURCE src/closest_pair_doubling.cpp src/kth_smallest.cpp src/main.cpp src/point_list.cpp)
set(UTILITIES utils/2d_problem.h utils/merge_sort.cpp utils/merge_sort.h utils/2d_problem.cpp)
set(TESTING test/algorithm_runner.cpp test/algorithm_runner.h test/program.cpp test/program.h)

add_executable(closest_pair_doubling
        ${MAIN_HEADERS}
        ${MAIN_SOURCE}
        ${UTILITIES}
        ${TESTING})
