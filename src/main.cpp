#include <iostream>
#include "../include/closest_pair_doubling.h"
#include "../test/program.h"
#include "../test/algorithm_runner.h"

typedef std::pair<std::pair<point, point>, double> DResult;

int main() {
//  program::launch();
  point_list list = point_list();
  list = point_list();
  list.random_initializer(2, 300000, -300000, 300000);
  std::cout << "\nNumber of points: " << (int) list.points.size() << std::endl;
  algorithm_runner::closest_pair_test(BRUTE_FORCE, list, 2);
  return 0;
}
