#include "2d_problem.h"

DResult ClosestPair2D::dist(point p, point q) {
  double xDiff = p.getCoordinate()[0] - q.getCoordinate()[0];
  double yDiff = p.getCoordinate()[1] - q.getCoordinate()[1];
  return std::pair<std::pair<point, point>, double>
          {std::pair<point, point> {p, q}, sqrt(xDiff * xDiff + yDiff * yDiff)};
}

DResult ClosestPair2D::algorithm2D(vector<point>& L) {
  std::sort(L.begin(), L.end(), compareX);
  vector<point> res_points;
  DResult d, d1, d2;
  int n = L.size();
  int mid_point = n / 2;
  double mid = L[mid_point].getCoordinate()[0];
  if (n <= 1) {
    return DResult
            {std::pair<point, point>{point(), point()}, std::numeric_limits<double>::infinity()};
  } else if (n == 2) {
    return dist(L[0], L[1]);
  }
  // merge_sort(L, true);
  vector<point> L1, L2, L_strip;
  for (int i = 0; i < n; i++) {
    if (i < mid_point) {
      L1.push_back(L[i]);
    } else {
      L2.push_back(L[i]);
    }
  }
  d1 = algorithm2D(L1);
  d2 = algorithm2D(L2);
  d = d1.second < d2.second ? d1 : d2;

  for (int i = (int)L1.size() - 1; i >= 0; i--) {
    if (L1[i].getCoordinate()[0] > mid - d.second) {
      L_strip.push_back(L1[i]);
    }
  }
  for (auto & i : L2) {
    if (i.getCoordinate()[0] < mid + d.second) {
      L_strip.push_back(i);
    }
  }
  sort(L_strip.begin(), L_strip.end(), compareY);
  L = merge(L1, L2, false);
  if (L_strip.size() <= 1) {
    return d;
  } else {
    DResult d_strip = DResult
            {std::pair<point, point>{point(), point()}, std::numeric_limits<double>::infinity()};
    for (int i = 0; i < L_strip.size(); i++) {
      for (int j = i + 1; j < i + 8; j++) {
        if (j >= L_strip.size()) {
          break;
        }
        DResult dist_successor = dist(L_strip[i], L_strip[j]);
        d_strip = dist_successor.second < d_strip.second ? dist_successor : d_strip;
      }
    }
    return d.second < d_strip.second ? d : d_strip;
  }
}
