#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>
#include <cmath>

class Point {
  private:
    std::vector<double> coordinate;

  public:
    explicit Point(std::vector<double> coordinate) {
      this->coordinate = std::move(coordinate);
    }
    Point()= default;

    double distance_to(const Point& another_point) {
      double total_square = 0;
      for (int i = 0; i < coordinate.size(); i++) {
        double iDiff = coordinate[i] - another_point.getCoordinate()[i];
        total_square += (iDiff) * (iDiff);
      }
      return sqrt(total_square);
    }
    std::vector<double> getCoordinate() const {
      return this -> coordinate;
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