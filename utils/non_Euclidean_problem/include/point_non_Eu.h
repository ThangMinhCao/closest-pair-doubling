#ifndef POINT_H
#define POINT_H
#include <utility>
#include <vector>
#include <iostream>
#include <cmath>
#include "boost/multiprecision/cpp_int.hpp"

using namespace boost::multiprecision;

class Point {
  public:
    std::vector<int> coordinate;
    explicit Point(std::vector<int> coordinate) {
      this->coordinate = std::move(coordinate);
    }
    Point()= default;

    cpp_int distance_to(const Point& another_point) {
      if (coordinate[0] == another_point.coordinate[0]) {
        return 0;
      }
      return boost::multiprecision::pow(cpp_int(4), std::max(coordinate[0], another_point.coordinate[0]));
    }

    friend bool operator== (const Point& p1, const Point& p2);
    friend bool operator!= (const Point& p1, const Point& p2);
    std::string toString() {
      std::string res = "(";
      for (int i = 0; i < coordinate.size(); i++) {
        res += std::to_string(coordinate[i]);
        if (i < coordinate.size() - 1) {
          res += ",";
        }
      }
      return res + ")";
    }
};

inline bool operator== (const Point& p1, const Point& p2) {
  return p1.coordinate == p2.coordinate;
}
inline bool operator!= (const Point& p1, const Point& p2) {
  return p1.coordinate != p2.coordinate;
}
#endif