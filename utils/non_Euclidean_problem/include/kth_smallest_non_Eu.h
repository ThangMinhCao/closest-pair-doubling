#ifndef K_SMALLEST_H
#define K_SMALLEST_H
#include <vector>
#include "boost/multiprecision/cpp_int.hpp"

using namespace boost::multiprecision;

typedef std::vector<cpp_int> DVect;

class KthSmallest {
  public:
    static cpp_int get(DVect& distances, int k);
//    static int1024_t get_with_sorting(DVect distances, int k);
};

#endif