#include "algorithm_runner.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "random_generator.h"
#include "2d_problem/2d_problem.h"

bool algorithm_runner::kth_smallest_test(int element_num, int range_start, int range_end){
  RandomInt random_int = RandomInt(1, element_num);
  int k = random_int.next();
  DVect distances;
  RandomDouble random_double(range_start, range_end);

  for (int i = 0; i < element_num; i++) {
    distances.push_back(random_double.next());
  }
  if (k > element_num) {
    printf("Invalid value of k");
    return false;
  }
  clock_t tStart = clock();
  double result_sort = kth_smallest::get_with_sorting(distances, k);
  double time1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
  tStart = clock();
  double result = kth_smallest::get(distances, 0, (int)distances.size() - 1, k);
  double time2 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
  printf("\n[1m[31mNumber of elements:[0m %d\n", element_num);
  printf("[1m[31mk:[0m %d\n", k);
  printf("[1m[31mValue range:[0m  %d to %d\n", range_start, range_end);
  printf("- O(nlogn) Result Using Sort: [0;32m%f[0m\n",result_sort);
  printf("  Time taken: \033[0;32m%fs\033[0m\n", time1);
  printf("- O(n) Result Using QuickSelect: [0;32m%f[0m\n", result);
  printf("  Time taken: \033[0;32m%fs\033[0m\n\n", time2);

  std::ofstream data_file;
  data_file.open("kth_smallest_tests.txt", std::ios_base::app);
  data_file << "Number of elements: " << element_num << "\n";
  data_file << "k value: " << k << "\n";
  data_file << "Value range: " << range_start << " to " << range_end << "\n";
  data_file << "- O(nlogn) Result Using Sort: " << result_sort << "\n";
  data_file << "  Time taken: " << time1 << "\n";
  data_file << "- O(n) Result Using QuickSelect: " << result << "\n";
  data_file << "  Time taken: " << time2 << "\n\n";
  data_file.close();
  return result_sort == result;
}

void algorithm_runner::closest_pair_test(Algorithm a, point_list S, int dimension) {
  double result;
  double d;
  clock_t tStart = clock();
  std::ofstream data_file;
  switch (a) {
    case CLOSEST_2D:
      printf("\033[1m\033[31m2D Algorithm:\033[0m\n");
      if (dimension != 2) {
        printf("Invalid Dimension!");
        result = 0.0;
        break;
      }
      result = ClosestPair2D::algorithm2D(S.points).second;
      break;
    case CLOSEST_DOUBLING:
      printf("\033[1m\033[31mDoubling Algorithm:\033[0m\n");
      data_file.open("sep_ann_loop_times.txt");
      data_file << "\nNUMBER OF TIMES THE ALGORITHM SEPANN REPEATS ITS LOOP:\n";
      data_file << "Repeat times" << std::setw(5) << "n" << std::setw(11) << "c\n";
      data_file.close();
      d = dimension == 2 ? log2(7) : log2(21);
      result = closest_pair_doubling::closest_pair(S, d);
      break;
    case BRUTE_FORCE:
      printf("\033[1m\033[31mBrute-force:\033[0m\n");
      result = closest_pair_doubling::brute_force(S);
      break;
  }
  printf("- The closest distance is: \033[32m%f\033[0m\n", result);
  printf("- Time taken: \033[0;32m%fs\033[0m\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  std::ofstream data_file2;
  data_file2.open("running_time_data.txt", std::ios_base::app);
  data_file2 << "- The closest distance is: " << result << "\n";
  data_file2 << "- Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
  data_file2.close();
}