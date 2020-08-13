#ifndef POINTLIST_H
#define POINTLIST_H
#include <point.h>
#include <random_generator.h>

class point_list {
  public:
    std::vector<point> points;
    point_list() = default;

    void random_initializer(int dimension, int point_num, double coor_start_range, double coor_end_range);
    void grid_initializer(double dist, int yFactor, int xFactor, int position);
};

#endif