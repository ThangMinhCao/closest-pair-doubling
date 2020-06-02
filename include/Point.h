#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>
#include <cmath>

class Point {
  public:
    std::vector<double> coordinate;
    Point(std::vector<double> coordinate) {
      this->coordinate = coordinate;
    }
    Point(){}

    double distance_to(Point another_point) {
      double total_square = 0;
      for (int i = 0; i < coordinate.size(); i++) {
        double iDiff = coordinate[i] - another_point.coordinate[i];
        total_square += (iDiff) * (iDiff);
      }
      return sqrt(total_square);
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