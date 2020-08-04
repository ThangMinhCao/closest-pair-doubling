#include "point_list.h"

void point_list::random_initializer(int dimension, int point_num, double coor_start_range, double coor_end_range) {
  RandomDouble random_double(coor_start_range, coor_end_range);
  for (int i = 0; i < point_num; i++) {
    std::vector<double> coor;
    coor.reserve(dimension);
    for (int j = 0; j < dimension; j++) {
      coor.push_back(random_double.next());
    }
    points.emplace_back(coor);
  }
}
