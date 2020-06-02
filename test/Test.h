#ifndef CLOSESTPAIRDOUBLING_TEST_H
#define CLOSESTPAIRDOUBLING_TEST_H
#include "kth_smallest.h"
#include "ClosestPairDoubling.h"

class Test {
  public:
    static bool kth_smallest_test(int element_num, int k, int range_start, int range_end);
    static void closest_pair_test(Algorithm a, PointList S, int dimension);
};


#endif //CLOSESTPAIRDOUBLING_TEST_H
