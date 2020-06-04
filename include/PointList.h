#ifndef POINTLIST_H
#define POINTLIST_H
#include "Point.h"
#include <random>
#include "RandomGenerator.h"

class PointList {
  public:
    std::vector<Point> points;

    PointList(int dimension, int point_num, int coor_start_range, int coor_end_range) {
      RandomDouble random_double(coor_start_range, coor_end_range);
//      RandomInt random_int(coor_start_range, coor_end_range);

      for (int i = 0; i < point_num; i++) {
        std::vector<double> coor;
        for (int j = 0; j < dimension; j++) {
          coor.push_back(random_double.next());
//           coor.push_back(random_int.next());
        }
        points.push_back(Point(coor));
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