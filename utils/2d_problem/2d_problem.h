#ifndef CLOSEST_PAIR_2D_H
#define CLOSEST_PAIR_2D_H
#include "point.h"
#include <vector>
#include <algorithm>

typedef std::pair<std::pair<point, point>, double> DResult;

class ClosestPair2D {
  private:
    static DResult dist(point p, point q);
    static double compareX(point p, point q) {
      return p.getCoordinate()[0] < q.getCoordinate()[0];
    }
    static double compareY(point p, point q) {
      return p.getCoordinate()[1] < q.getCoordinate()[1];
    }

  public:
    ClosestPair2D() = default;
    static DResult algorithm2D(std::vector<point>& L);

};
#endif