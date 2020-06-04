#include <iostream>
#include <algorithm>
#include <limits>
#include "../include/kth_smallest.h"
#include "../include/RandomGenerator.h"

void swap (double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}
double find(DVect& distances, int start, int end, int k) {
  if (start == end) {return distances[start];}
  // partitioning and moving all elements smaller than pivot to the left of it and vice versa
  // 1/ swapping the random pivot to the end
  RandomInt random_int_gen = RandomInt(start, end);
  swap(&distances[random_int_gen.next()], &distances[end]);
//  swap(distances, random_int_gen.next(), end);
  double pivot = distances[end];
  int slow = start;
  int fast = start;
  // 2/ moving the smaller elements to the left and larger elements to the right
  while (fast < end) {
    if (distances[slow] > pivot) {
      while (fast < end and distances[fast] > pivot) {
        fast++;
      }
//      if (distances[fast] >= pivot) {
//        break;
//      }
//      swap(&distances[slow], &distances[fast]);
      if (distances[fast] < pivot) {
        swap(&distances[slow], &distances[fast]);
//        swap(distances, slow, fast);
      } else {
        break;
      }
    }
    fast++;
    slow++;
  }
  // 3/ swapping the pivot from end back to its original place
//  std::cout << "Fast: " << fast << " Slow: " << slow << std::endl;
//  std::cout << "Before: " << std::endl;
//  print_dvect(distances, pivot);
  swap(&distances[slow], &distances[end]);
//  std::cout << "After: " << std::endl;
//  print_dvect(distances, pivot);
//  swap(distances, slow, end);
  if (k == slow - start + 1) {
    return distances[slow];
  } else if (k < slow - start + 1) {
    return find(distances, start, slow - 1, k);
  } else {
    return find(distances, slow + 1, end, k - slow + start - 1);
  }
}

double kth_smallest(DVect& distances, int k) {
  if (k < 1 or k > distances.size()) {
    return std::numeric_limits<double>::max();
  }
  return find(distances, 0, (int)distances.size() - 1, k);
}

bool compare(double x, double y) {
  return x < y;
}

double kth_smallest_with_sorting(DVect distances, int k) {
  std::sort(distances.begin(), distances.end(), compare);
  return distances[k - 1]; 
}