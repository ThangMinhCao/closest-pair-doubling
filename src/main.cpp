#include <iostream>
#include "../include/ClosestPairDoubling.h"
//#include <utility>
#include "../test/Test.h"

typedef std::pair<std::pair<Point, Point>, double> DResult;

typedef std::pair<int, int> Range;

void print_vec(const DVect& vec) {
  for (double i : vec) {
    printf("%f", i);
  }
  printf("\n");
}

int main() {
  srand((unsigned)time(nullptr));
  int dimension = 2;
  int point_num = 300000;
  int rangeS = 0;
  int rangeE = 300000;

  PointList list = PointList(dimension, point_num, rangeS, rangeE);
  printf("Number of Points: %d\n", point_num);
//  Test::closest_pair_test(CLOSEST_2D, list, dimension);
  Test::closest_pair_test(CLOSEST_DOUBLING, list, dimension);
  Test::closest_pair_test(BRUTE_FORCE, list, dimension);
  return 0;
}
