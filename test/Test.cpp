#include "Test.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "RandomGenerator.h"
#include "../utils/2d_problem.h"

bool Test::kth_smallest_test(int element_num, int k, int range_start, int range_end){
  DVect distances;
  RandomDouble random_gen(range_start, range_end);

  for (int i = 0; i < element_num; i++) {
    distances.push_back(random_gen.next());
  }
  if (k > element_num) {
    printf("Invalid value of k");
    return false;
  }
  clock_t tStart = clock();
  double result_sort = KthSmallest::get_with_sorting(distances, k);
  double time1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;

   tStart = clock();
  double result = KthSmallest::get(distances, k);
  double time2 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
//  double result = kth_smallest(distances, 0, (int)distances.size(), k);
  if (result != result_sort) {
    printf("\nExpected Result: %f\n",result_sort);
    printf("Algorithm with sorting time taken: \033[0;32m%fs\033[0m\n\n", time1);

    printf("Result Using QuickSort Technique: %f\n", result);
    printf("Algorithm without sorting time taken: \033[0;32m%fs\033[0m\n\n", time2);
  }
  return result_sort == result;
}

void Test::closest_pair_test(Algorithm a, PointList S, int dimension) {
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
      data_file << "NUMBER OF TIMES THE ALGORITHM SEPANN REPEATS ITS LOOP:\n";
      data_file << "Repeat times" << std::setw(5) << "n" << std::setw(11) << "c\n";
      data_file.close();
      d = dimension == 2 ? log2(7) : log2(21);
      result = ClosestPairDoubling::closest_pair(S, d);
      break;
    case BRUTE_FORCE:
      printf("\033[1m\033[31mBrute-force:\033[0m\n");
      result = ClosestPairDoubling::brute_force(S);
      break;
  }
  printf("- The closest distance is: \033[32m%f\033[0m\n", result);
  printf("- Time taken: \033[0;32m%fs\033[0m\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
