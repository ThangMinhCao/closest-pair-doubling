#ifndef K_SMALLEST_H
#define K_SMALLEST_H
#include <vector>
typedef std::vector<double> DVect;

class KthSmallest {
  public:
    static double get(DVect& distances, int k);
    static double get_with_sorting(DVect distances, int k);
};

#endif