#ifndef K_SMALLEST_H
#define K_SMALLEST_H
#include <vector>
typedef std::vector<double> DVect;

double kth_smallest(DVect& distances, int k);
double kth_smallest_with_sorting(DVect distances, int k);

#endif