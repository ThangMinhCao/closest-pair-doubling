#include <iostream>
#include <algorithm>
#include "kth_smallest.h"
#include "random_generator.h"

void kth_smallest::swap (double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

int kth_smallest::partition(DVect& distances, int start, int end) {
  double pivot = distances[end];
  int slow = start;
  int fast = start;
  // 2/ moving the smaller elements to the left and larger elements to the right
  while (fast < end) {
    if (distances[slow] > pivot) {
      while (fast < end and distances[fast] > pivot) {
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
  return slow;
}
double kth_smallest::get(DVect& distances, int start, int end, int k) {
  if (k < 1 or k > distances.size()) {
    return std::numeric_limits<double>::max();
  }

  if (start == end) {return distances[start];}
  //  swapping the random pivot to the end
  RandomInt random_int_gen = RandomInt(start, end);
  swap(&distances[random_int_gen.next()], &distances[end]);
  int cur_pivot = partition(distances, start, end);
  // recursively call one of two side
  if (k == cur_pivot - start + 1) {
    return distances[cur_pivot];
  } else if (k < cur_pivot - start + 1) {
    return get(distances, start, cur_pivot - 1, k);
  } else {
    return get(distances, cur_pivot + 1, end, k - cur_pivot + start - 1);
  }
}

bool compare(double x, double y) {
  return x < y;
}

double kth_smallest::get_with_sorting(DVect distances, int k) {
  std::sort(distances.begin(), distances.end(), compare);
  return distances[k - 1]; 
}