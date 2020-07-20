#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H
#include "PointList.h"

typedef std::vector<double> DVect;

enum Algorithm {
  CLOSEST_DOUBLING,
  CLOSEST_2D,
  BRUTE_FORCE
};

class ClosestPairDoubling {
  private:
    static std::tuple<Point, double, DVect> sep_ann(PointList &S, int n, double mu, double c);
    static std::pair<Point, double> sparse_sep_ann(PointList &S, int n, double d, int t);

  public:
    ClosestPairDoubling() = default;
    static double brute_force(PointList &S);
    static double closest_pair(PointList &S, double d, int recursion=0);
};

#endif