#ifndef K_SMALLEST_H
#define K_SMALLEST_H
#include <vector>
typedef std::vector<double> DVect;

class kth_smallest {
  private:
    static void swap (double *a, double *b);
    static int partition(DVect& distances, int start, int end);

  public:
    static double get(DVect& distances, int start, int end, int k);
    static double get_with_sorting(DVect distances, int k);
};

#endif