#include <iostream>
#include "../include/ClosestPairDoubling.h"
//#include <utility>
#include "../test/Test.h"

typedef std::pair<std::pair<Point, Point>, double> DResult;

typedef std::pair<int, int> Range;

void print_vec(const DVect& vec) {
  for (double i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  srand((unsigned)time(nullptr));
  int dimension = 2;
  int point_num = 10;
  int rangeS = 0;
  int rangeE = 300000;

  PointList list = PointList(dimension, point_num, rangeS, rangeE);
  PointList list2 = PointList(dimension, point_num, rangeS, rangeE);
  std::cout << "Number of Points: " << point_num << std::endl;
//  Test::closest_pair_test(CLOSEST_2D, list, dimension);
//  Test::closest_pair_test(CLOSEST_DOUBLING, list, dimension);
//  Test::closest_pair_test(BRUTE_FORCE, list, dimension);
  list.print_points();
  list2.print_points();
  return 0;
}
