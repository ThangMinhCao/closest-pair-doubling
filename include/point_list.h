#ifndef POINTLIST_H
#define POINTLIST_H
#include <point.h>
#include <random_generator.h>

class point_list {
  public:
    std::vector<point> points;

    void random_initializer(int dimension, int point_num, double coor_start_range, double coor_end_range);

    void grid_initializer(double dist, int yFactor, int xFactor, int position) {
      int y = 0;
      while (y < yFactor) {
        int x = 0;
        while (x < xFactor) {
          std::vector<double> coor;
          coor.push_back(position + (x++) * dist);
          coor.push_back(position + (y) * dist);
          points.push_back(point(coor));
        }
        y++;
      }
    }

    point_list() {}
    void print_points() {
      for (point p: points) {
        printf("%s", p.toString().c_str());
      }
      printf("\n");
    }
};

#endif