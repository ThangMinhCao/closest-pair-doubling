#include "../include/ClosestPairDoubling.h"
#include "../include/kth_smallest.h"
#include <tuple>
#include <fstream>
#include <iomanip>

double ClosestPairDoubling::brute_force(PointList &S) {
  double result = std::numeric_limits<double>::max();
  for (int i = 0; i < S.points.size(); i++) {
    for (int j = i + 1; j < S.points.size(); j++) {
      if (S.points[i].distance_to(S.points[j])< result) {
        result = S.points[i].distance_to(S.points[j]);
      }
    }
  }
  return result;
}

std::tuple<Point, double, DVect> ClosestPairDoubling::sep_ann(PointList &S, int n, double d, double mu, double c) {
  double Rp = 0.0;
  Point p;
  int outer_ball_count = (n / 2) + 1;
  
  // Random integer generator
  RandomInt int_gen(0, n - 1);
  /**
   * 1/ The while loop repeats the procedure
   **/
  DVect distances_from_p;
  int count = 0;
  while (Rp == 0.0 or outer_ball_count > std::floor(n / 2)) {
    count++;
    distances_from_p.clear();
    int random_index = int_gen.next();
    p = S.points[random_index];
    for (const Point& point: S.points) {
      if (point != p) {
        distances_from_p.push_back(p.distance_to(point));
      }
    }
    Rp = kth_smallest(distances_from_p, ceil(n / c));
    outer_ball_count = 0;
    for (double dist: distances_from_p) {
      if (dist <= mu * Rp) {
        outer_ball_count++;
      }
    }
  }
  std::ofstream data_file;
  data_file.open("sep_ann_loop_times.txt", std::ios_base::app);
  data_file << std::setw(7) << count << std::setw(13) << n << std::setw(10) << c << "\n";
  data_file.close();
  return std::make_tuple(p, Rp, distances_from_p);
}

std::pair<Point, double> ClosestPairDoubling::sparse_sep_ann(PointList &S, int n, double d, int t) {
  const double e = std::exp(1.0);
  double c = 2 * pow(4 * e, d);
  std::tuple<Point, double, DVect> sep_ann_res = sep_ann(S, n, d, e, c);

  // followings are result of sep_ann() function
  Point p = std::get<0>(sep_ann_res);
  double R_prime = std::get<1>(sep_ann_res);
  DVect distances_from_p = std::get<2>(sep_ann_res);

  int Ai_size = n / t + 1;
  // random generator from 1 to t
  RandomInt range_t_random(1, t);

  double R;
  while (Ai_size > n / t) {
    int random_i = range_t_random.next();
    double Ri = pow(1 + 1.0 / t, random_i) * R_prime;
    R = pow(1 + 1.0 / t, random_i - 1) * R_prime;
    Ai_size = 0;
    for (double dist: distances_from_p) {
      if (R <= dist and dist <= Ri) {
        Ai_size++;
      }
    }
  }
  return std::pair<Point, double> {p, R};
}

double ClosestPairDoubling::closest_pair(PointList &S, double d, int recursion) {

  int n = (int)S.points.size();
  const double e = std::exp(1.0);
  double delta0;
  if (n < 2 * pow(16 * e, d)) {
    return brute_force(S);
  } else {
    int t = floor((1 / (16 * std::exp(1.0))) * pow((double)n / 2, 1 / d));
    std::pair<Point, double> ssann_result = sparse_sep_ann(S, n, d, t);
    Point p = ssann_result.first;
    double R = ssann_result.second;

    PointList S1orS2 = PointList();
    PointList S2orS3 = PointList();
    for (const Point& point: S.points) {
      if (point != p){
        double d_to_p = p.distance_to(point);
        if (d_to_p <= R) {
          S1orS2.points.push_back(point);
        } else if (d_to_p > R and d_to_p <= (1 + 1/t) * R) {
          S1orS2.points.push_back(point);
          S2orS3.points.push_back(point);
        } else {
          S2orS3.points.push_back(point);
        }
      }
    }
    std::vector<Point>().swap(S.points);

    double delta1 = closest_pair(S1orS2, d, ++recursion);
    double delta2 = closest_pair(S2orS3, d, ++recursion);
    delta0 = std::min(delta1, delta2);
  }
  return delta0;
}
