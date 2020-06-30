#ifndef POINTLIST_H
#define POINTLIST_H
#include "Point.h"
#include <random>
#include "RandomGenerator.h"

class PointList {
  public:
    std::vector<Point> points;

    void random_initializer(int dimension, int point_num, int coor_start_range, int coor_end_range) {
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

    void squares_initializer(int dimension, int point_num, double d) {
      double c = 2 * pow(4 * std::exp(1.0), d);
      int m = ceil(point_num / c);
      int b_left_corner = 0;
      while (point_num > 0) {
        RandomDouble random_double(b_left_corner, b_left_corner + 1);
        for (int i = 0; i < m; i++) {
          if (!point_num) {
            break;
          }
          std::vector<double> coor;
          for (int j = 0; j < dimension; j++) {
            coor.push_back(random_double.next());
          }
          points.push_back(Point(coor));
          point_num--;
        }
        b_left_corner += 10;
      }
    }

    void rect_initializer(int dimension, int point_num, int coor_start_range, int coor_end_range) {
      int y = 0;
      RandomDouble random_double(coor_start_range, coor_end_range);
      while (y < 500) {
        double h_dist = (coor_end_range - coor_start_range) / 500;
        int x = 0;
        while (x < 600) {
          std::vector<double> coor;
          coor.push_back(coor_start_range + x * h_dist);
          coor.push_back(coor_start_range + y * h_dist);
          x++;
          points.push_back(Point(coor));
          point_num--;
        }
        y++;
      }
      while (point_num > 0) {
        std::vector<double> coor;
        coor.push_back(random_double.next());
        coor.push_back(random_double.next());
        points.push_back(Point(coor));
        point_num--;
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