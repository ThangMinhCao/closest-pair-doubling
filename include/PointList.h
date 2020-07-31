#ifndef POINTLIST_H
#define POINTLIST_H
#include <Point.h>
#include <RandomGenerator.h>

class PointList {
  public:
    std::vector<Point> points;

    void random_initializer(int dimension, int point_num, double coor_start_range, double coor_end_range) {
      RandomDouble random_double(coor_start_range, coor_end_range);
      for (int i = 0; i < point_num; i++) {
        std::vector<double> coor;
        for (int j = 0; j < dimension; j++) {
          coor.push_back(random_double.next());
        }
        points.push_back(Point(coor));
      }
    }

    void grid_initializer(double dist, int yFactor, int xFactor, int position) {
      int y = 0;
      while (y < yFactor) {
        int x = 0;
        while (x < xFactor) {
          std::vector<double> coor;
          coor.push_back(position + (x++) * dist);
          coor.push_back(position + (y) * dist);
          points.push_back(Point(coor));
        }
        y++;
      }
    }

    PointList() {}
    void print_points() {
      for (Point p: points) {
        printf("%s", p.toString().c_str());
      }
      printf("\n");
    }
};

#endif