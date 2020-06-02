#ifndef CLOSEST_PAIR_2D_H
#define CLOSEST_PAIR_2D_H
#include "merge_sort.h"
#include <vector>
#include <algorithm>

typedef std::pair<std::pair<Point, Point>, double> DResult;

class ClosestPair2D {
  private:
    static DResult dist(Point p, Point q);
    static double compareX(Point p, Point q) {
      return p.coordinate[0] < q.coordinate[0];
    }
    static double compareY(Point p, Point q) {
      return p.coordinate[1] < q.coordinate[1];
    }

  public:
    ClosestPair2D() = default;
    static DResult algorithm2D(vector<Point>& L);

};
#endif