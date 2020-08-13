#include "../include/closest_pair_doubling.h"
#include "../include/kth_smallest.h"
#include <tuple>
#include <fstream>
#include <iomanip>

double closest_pair_doubling::brute_force(point_list &S) {
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
std::tuple<point, double, DVect>
        closest_pair_doubling::sep_ann(point_list &S, int n, double mu, double c)
        {
  point p;
  double Rp = -1.0;

  int outer_ball_count = (n / 2) + 1; // this variable store the number of points in the outer ball with R = mu * Rp
  RandomInt int_gen(0, n - 1); // the random integer generator
  DVect distances_from_p; // the vector store the distances between p and other points
  int count = 0;
  while (Rp == -1.0 or outer_ball_count > std::floor(n / 2)) { // The loop check if outer_ball_count is <= n/2 or not
    count++;
    distances_from_p.clear();
    int random_index = int_gen.next();
    p = S.points[random_index];
    // store the all the distances from p to all other points to the vector
    for (const point& point: S.points) {
      distances_from_p.push_back(p.distance_to(point));
    }
    Rp = kth_smallest::get(distances_from_p, 0, (int)distances_from_p.size(), ceil(n / c));
    outer_ball_count = 0;
    for (double dist: distances_from_p) {
      if (dist <= mu * Rp) {
        outer_ball_count++;
      }
    }
  }
  // This part is only to write the data into a text file
  std::ofstream data_file;
  data_file.open("sep_ann_loop_times.txt", std::ios_base::app);
  data_file << std::setw(7) << count << std::setw(13) << n << std::setw(10) << c << "\n";
  data_file.close();
  return std::make_tuple(p, Rp, distances_from_p);
}

std::pair<point, double> closest_pair_doubling::sparse_sep_ann(point_list &S, int n, double d, int t) {
  const double e = std::exp(1.0);
  double c = 2 * pow(4 * e, d);
  std::tuple<point, double, DVect> sep_ann_res = sep_ann(S, n, e, c);

  // followings are result of sep_ann() function
  point p = std::get<0>(sep_ann_res);
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
  return std::pair<point, double> {p, R};
}

double closest_pair_doubling::closest_pair(point_list &S, double d, int recursion) {
  int n = (int)S.points.size();
  const double e = std::exp(1.0);
  double delta0;
  if (n < 2 * pow(16 * e, d)) {
    return brute_force(S);
  } else {
    int t = floor((1 / (16 * std::exp(1.0))) * pow((double)n / 2, 1 / d));
    std::pair<point, double> ssann_result = sparse_sep_ann(S, n, d, t);
    point p = ssann_result.first;
    double R = ssann_result.second;

    point_list S1orS2 = point_list();
    point_list S2orS3 = point_list();
    for (const point& point: S.points) {
      double d_to_p = p.distance_to(point);
      if (d_to_p <= R) {
        S1orS2.points.push_back(point);
      } else if (d_to_p > R and d_to_p <= (1 + 1.0/t) * R) {
        S1orS2.points.push_back(point);
        S2orS3.points.push_back(point);
      } else {
        S2orS3.points.push_back(point);
      }
    }
    std::vector<point>().swap(S.points); // free the memory that store the vector S

    double delta1 = closest_pair(S1orS2, d, ++recursion);
    double delta2 = closest_pair(S2orS3, d, ++recursion);
    delta0 = std::min(delta1, delta2);
  }
  return delta0;
}
