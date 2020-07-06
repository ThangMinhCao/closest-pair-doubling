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
  int rangeS = -300000;
  int rangeE = 300000;

  PointList list = PointList();
//  list.random_initializer(dimension, point_num, rangeS, rangeE);
//  list.squares_initializer(dimension, point_num, log2(7));
//  list.isolated_initializer(point_num, rangeS, rangeE);
  list.rect_initializer(dimension, point_num, rangeS, rangeE);
//  printf("Number of Points: %d\n", point_num);
//  printf("\n[1m[31mNumber of Points:[0m %s\n", "300,000");
  printf("\n[1m[31mNumber of Points:[0m %d\n", (int)list.points.size());
  printf("[1m[31mCoordinates Range:[0m -300,000 to 300,000\n\n");
//  printf("[1m[31mCoordinates Range:[0m -100000 to 100000\n\n");
  Test::closest_pair_test(CLOSEST_2D, list, dimension);
  Test::closest_pair_test(CLOSEST_DOUBLING, list, dimension);
  Test::closest_pair_test(BRUTE_FORCE, list, dimension);
//  Test::kth_smallest_test(100000000, 76543210, -100000, 100000);
  return 0;
}
