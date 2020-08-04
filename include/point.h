#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>
#include <cmath>

class point {
  private:
    std::vector<double> coordinate;

  public:
    explicit point(std::vector<double> coordinate) {
      this->coordinate = std::move(coordinate);
    }
    point()= default;

    double distance_to(const point& another_point) {
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

    friend bool operator== (const point& p1, const point& p2);
    friend bool operator!= (const point& p1, const point& p2);

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

inline bool operator== (const point& p1, const point& p2) {
  return p1.coordinate == p2.coordinate;
}
inline bool operator!= (const point& p1, const point& p2) {
  return p1.coordinate != p2.coordinate;
}
#endif