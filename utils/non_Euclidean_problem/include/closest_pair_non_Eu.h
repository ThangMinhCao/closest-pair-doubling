#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H
#include "../include/point_list_non_Eu.h"
#include "boost/multiprecision/cpp_dec_float.hpp"

typedef std::vector<cpp_int> DVect;

using Float = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<0>>;

enum Algorithm {
  CLOSEST_DOUBLING,
  CLOSEST_2D,
  BRUTE_FORCE
};

class ClosestPairDoubling {
  private:
    std::tuple<Point, cpp_int , DVect>
            sep_ann(PointList &S, int n, double mu, double c);
    std::pair<Point, Float>
            sparse_sep_ann(PointList &S, int n, double d, int t);

  public:
    int dist_call_counter;
    ClosestPairDoubling(){
      dist_call_counter = 0;
    };
    cpp_int brute_force(PointList &S);
    cpp_int closest_pair(PointList &S, double d);
};

#endif