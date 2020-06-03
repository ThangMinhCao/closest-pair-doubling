#include "Test.h"
#include <iostream>
#include "RandomGenerator.h"
#include "../utils/2d_problem.h"

bool Test::kth_smallest_test(int element_num, int k, int range_start, int range_end){
  DVect distances;
//  std::cout << "\nNumber of points: \033[31m" << element_num << "\033[0m" << std::endl;
  srand(time(nullptr));
  RandomDouble random_gen(range_start, range_end);

  for (int i = 0; i < element_num; i++) {
    distances.push_back(random_gen.next());
  }
  if (k > element_num) {
    std::cout << "Invalid value of k" << std::endl;
    return false;
  }

//  double result_sort = kth_smallest_with_sorting(distances_copy, k);
//  double result = kth_smallest(distances, k);
//  if (result != result_sort) {
//    std::cout << "WRONG!" << "  ";
//  }
//  std::cout << std::endl;

  clock_t tStart = clock();
  double result_sort = kth_smallest_with_sorting(distances, k);
  double time1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;

   tStart = clock();
  double result = kth_smallest(distances, k);
  double time2 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
//  double result = kth_smallest(distances, 0, (int)distances.size(), k);
  if (result != result_sort) {
    std::cout << "\nExpected Result: " << result_sort << std::endl;
    printf("Algorithm with sorting time taken: \033[0;32m%fs\033[0m\n\n", time1);
    std::cout << "Result Using QuickSort Technique: " << result << std::endl;
    printf("Algorithm without sorting time taken: \033[0;32m%fs\033[0m\n\n", time2);
  }
  return result_sort == result;
}

void Test::closest_pair_test(Algorithm a, PointList S, int dimension) {
  double result;
  double d;
  clock_t tStart = clock();
  switch (a) {
    case CLOSEST_2D:
      printf("\033[1m\033[31m2D Algorithm:\033[0m\n");
      if (dimension != 2) {
        std::cout << "Invalid Dimension!" << std::endl;
        result = 0.0;
        break;
      }
      result = ClosestPair2D::algorithm2D(S.points).second;
      break;
    case CLOSEST_DOUBLING:
      printf("\033[1m\033[31mDoubling Algorithm:\033[0m\n");
      d = dimension == 2 ? log2(7) : log2(21);
      result = ClosestPairDoubling::closest_pair(S, d);
      break;
    case BRUTE_FORCE:
      printf("\033[1m\033[31mBrute-force:\033[0m\n");
      result = ClosestPairDoubling::brute_force(S);
      break;
  }
  std::cout << "- The closest distance is: \033[32m" << result << "\033[0m" << std::endl;
  printf("- Time taken: \033[0;32m%fs\033[0m\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
