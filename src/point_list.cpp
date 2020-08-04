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

void point_list::grid_initializer(double dist, int yFactor, int xFactor, int position) {
  int y = 0;
  while (y < yFactor) {
    int x = 0;
    while (x < xFactor) {
      std::vector<double> coor;
      coor.push_back(position + (x++) * dist);
      coor.push_back(position + (y) * dist);
      points.emplace_back(coor);
    }
    y++;
  }
}

