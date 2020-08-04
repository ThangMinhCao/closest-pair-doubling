#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H
#include "point_list.h"

typedef std::vector<double> DVect;

enum Algorithm {
  CLOSEST_DOUBLING,
  CLOSEST_2D,
  BRUTE_FORCE
};

class closest_pair_doubling {
  private:
    static std::tuple<point, double, DVect> sep_ann(point_list &S, int n, double mu, double c);
    static std::pair<point, double> sparse_sep_ann(point_list &S, int n, double d, int t);

  public:
    closest_pair_doubling() = default;
    static double brute_force(point_list &S);
    static double closest_pair(point_list &S, double d, int recursion=0);
};

#endif