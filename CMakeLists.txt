cmake_minimum_required(VERSION 3.16)
project(ClosestPairDoubling)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(utils)

set(NON_EUCLIDEAN
        utils/non_Euclidean_problem/include/closest_pair_non_Eu.h
        utils/non_Euclidean_problem/include/kth_smallest_non_Eu.h
        utils/non_Euclidean_problem/include/point_list_non_Eu.h
        utils/non_Euclidean_problem/include/point_non_Eu.h
        utils/non_Euclidean_problem/src/closest_pair_non_Eu.cpp
        utils/non_Euclidean_problem/src/kth_smallest_non_Eu.cpp
        utils/non_Euclidean_problem/test/algorithm_runner_non_Eu.cpp
        utils/non_Euclidean_problem/test/algorithm_runner_non_Eu.h
        utils/non_Euclidean_problem/test/program_non_Eu_part.cpp
        utils/non_Euclidean_problem/test/program_non_Eu_part.h)
set(MAIN_HEADERS include/closest_pair_doubling.h include/kth_smallest.h include/point.h
        include/point_list.h include/random_generator.h)
set(MAIN_SOURCE src/closest_pair_doubling.cpp src/kth_smallest.cpp src/main.cpp src/point_list.cpp)
set(UTILITIES utils/2d_problem/2d_problem.h utils/2d_problem/merge_sort.cpp
        utils/2d_problem/merge_sort.h utils/2d_problem/2d_problem.cpp
        ${NON_EUCLIDEAN})
set(TESTING test/algorithm_runner.cpp test/algorithm_runner.h test/program.cpp test/program.h utils/user_io/user_io.cpp utils/user_io/user_io.h)

add_executable(closest_pair_doubling
        ${MAIN_HEADERS}
        ${MAIN_SOURCE}
        ${UTILITIES}
        ${TESTING})
