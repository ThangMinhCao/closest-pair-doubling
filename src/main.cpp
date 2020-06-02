#include <iostream>
#include "../include/kth_smallest.h"
#include "../include/RandomGenerator.h"
#include "../include/ClosestPairDoubling.h"
#include <utility>
#include <limits>
#include "../test/Test.h"

#include "../utils/2d_problem.h"
typedef std::pair<std::pair<Point, Point>, double> DResult;

typedef std::pair<int, int> Range;

void print_vec(DVect vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

double brute_force(std::vector<Point> &S) {
  double result = std::numeric_limits<double>::max();
  for (int i = 0; i < S.size(); i++) {
    for (int j = i + 1; j < S.size(); j++) {
      if (S[i].distance_to(S[j]) < result) {
        result = S[i].distance_to(S[j]);
      }
    }
  }
  return result;
}

int main() {
  int dimension = 2;
  int point_num = 300000;
  int rangeS = 0;
  int rangeE = 300000;

  PointList list = PointList(dimension, point_num, rangeS, rangeE);
  std::cout << "Number of Points: " << point_num << std::endl;
  Test::closest_pair_test(CLOSEST_2D, list, dimension);
  Test::closest_pair_test(CLOSEST_DOUBLING, list, dimension);
  Test::closest_pair_test(BRUTE_FORCE, list, dimension);
  return 0;
}
