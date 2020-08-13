#include <limits>
#include "../include/kth_smallest_non_Eu.h"
#include "random_generator.h"

void swap (cpp_int *a, cpp_int *b) {
  cpp_int temp = *a;
  *a = *b;
  *b = temp;
}

cpp_int find(DVect& distances, int start, int end, int k) {
  if (start == end) {return distances[start];}
  // partitioning and moving all elements smaller than pivot to the left of it and vice versa
  // 1/ swapping the random pivot to the end
  RandomInt random_int_gen = RandomInt(start, end);
  swap(&distances[random_int_gen.next()], &distances[end]);
  cpp_int pivot = distances[end];
  int slow = start;
  int fast = start;
  // 2/ moving the smaller elements to the left and larger elements to the right
  while (fast < end) {
    if (distances[slow] > pivot) {
      while (fast < end && distances[fast] > pivot) {
        fast++;
      }
      if (distances[fast] < pivot) {
        swap(&distances[slow], &distances[fast]);
      } else {
        break;
      }
    }
    fast++;
    slow++;
  }
  // 3/ swapping the pivot from end back to its original place
  swap(&distances[slow], &distances[end]);

  if (k == slow - start + 1) {
    return distances[slow];
  } else if (k < slow - start + 1) {
    return find(distances, start, slow - 1, k);
  } else {
    return find(distances, slow + 1, end, k - slow + start - 1);
  }
}

cpp_int KthSmallest::get(DVect& distances, int k) {
  if (k < 1 || k > distances.size()) {
    return std::numeric_limits<cpp_int>::max();
  }
  return find(distances, 0, (int)distances.size() - 1, k);
}
