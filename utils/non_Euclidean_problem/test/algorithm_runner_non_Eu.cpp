#include "algorithm_runner_non_Eu.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void Test::closest_pair_test_with_strange_space(PointList S, Algorithm a) {
  cpp_int result;
  clock_t tStart = clock();
  std::ofstream data_file;
  std::ofstream runtime_file;
  runtime_file.open("non_Eu_running_time.txt", std::ios_base::app);
  runtime_file << "Number of 'Points': " << S.points.size() << "\n";
  ClosestPairDoubling calculator = ClosestPairDoubling();
  switch (a) {
    case BRUTE_FORCE:
      printf("\033[1m\033[31mBrute-force:\033[0m\n");
      runtime_file << "Brute-force:" << "\n";
      result = calculator.brute_force(S);
      break;
    case CLOSEST_DOUBLING:
      printf("\nNumber of 'Points': %zu\n", S.points.size());
      printf("\033[1m\033[31mClosest Pair Strange Metric Space:\033[0m\n");
      result = calculator.closest_pair(S, 1);
      data_file.open("sep_ann_loop_times.txt", std::ios_base::app);
      data_file << "NUMBER OF TIMES THE ALGORITHM SEPANN REPEATS ITS LOOP:\n";
      data_file << "Repeat times" << std::setw(8) << "n" << std::setw(11) << "c\n";
      data_file.close();
      break;
  }
  runtime_file << "- The closest distance is: " << result << "\n";
  runtime_file << "- Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s\n";
//  runtime_file << "- Number of dist() function calls: " << calculator.dist_call_counter;
  runtime_file << "\n\n";
  runtime_file.close();
  std::cout << "- The closest distance is: \033[32m" << result << "\033[0m\n";
  printf("- Time taken: \033[0;32m%fs\033[0m\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//  std::cout << "- Number of dist() function calls: \033[32m" << calculator.dist_call_counter << "\033[0m\n";
}
