#ifndef MERGESORT_H
#define MERGESORT_H
#include "point.h"
#include <vector>

using namespace std;

vector<point> merge_sort(vector<point>& L, bool x);
vector<point> merge(vector<point> const &L1, vector<point> const &L2, bool x);

#endif