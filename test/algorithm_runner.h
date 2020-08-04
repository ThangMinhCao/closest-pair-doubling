#ifndef CLOSESTPAIRDOUBLING_ALGORITHM_RUNNER_H
#define CLOSESTPAIRDOUBLING_ALGORITHM_RUNNER_H
#include "kth_smallest.h"
#include "closest_pair_doubling.h"

class algorithm_runner {
  public:
    static bool kth_smallest_test(int element_num, int k, int range_start, int range_end);
    static void closest_pair_test(Algorithm a, point_list S, int dimension);
};


#endif //CLOSESTPAIRDOUBLING_ALGORITHM_RUNNER_H
