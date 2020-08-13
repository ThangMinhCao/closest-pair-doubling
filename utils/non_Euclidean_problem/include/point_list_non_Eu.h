#ifndef POINTLIST_H
#define POINTLIST_H
#include "point_non_Eu.h"
#include <random>
#include "random_generator.h"

class PointList {
  public:
    std::vector<Point> points;
    void strange_metric_initializer(int point_num, int n) {
      std::set<int> visited;
      RandomInt random_gen(1, n);
      for (int i = 0; i < point_num; i++) {
        std::vector<int> coor;
        int random_coor = random_gen.next();
        if (points.size() < n) {
          while (visited.find(random_coor) != visited.end()) {
            random_coor = random_gen.next();
          }
        }
        visited.insert(random_coor);
        coor.push_back(random_coor);
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