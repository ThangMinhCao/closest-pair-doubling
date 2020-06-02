cmake_minimum_required(VERSION 3.16)
project(ClosestPairDoubling)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(utils)

set(MAIN_HEADERS include/ClosestPairDoubling.h include/kth_smallest.h include/Point.h
        include/PointList.h include/RandomGenerator.h)
set(MAIN_SOURCE src/ClosestPairDoubling.cpp src/kth_smallest.cpp src/main.cpp)
set(UTILITIES utils/2d_problem.h utils/merge_sort.cpp utils/merge_sort.h utils/2d_problem.cpp)
set(TESTING test/Test.cpp test/Test.h)

add_executable(closest_pair_doubling
        ${MAIN_HEADERS}
        ${MAIN_SOURCE}
        ${UTILITIES}
        ${TESTING})
