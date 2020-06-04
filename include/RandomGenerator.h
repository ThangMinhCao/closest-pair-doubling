#ifndef RANDOM_GEN_H
#define RANDOM_GEN_H 
#include <random>

class RandomInt{
public:
    RandomInt(int start, int end) 
        : generator{std::random_device{}()}, int_dist(start, end) {}
    int next() { return int_dist(generator); } 

private:
    std::mt19937 generator;
    std::uniform_int_distribution<> int_dist;
};

class RandomDouble{
public:
    RandomDouble(int start, int end) 
        : generator{std::random_device{}()}, double_dist(start, end) {}
    double next() { return double_dist(generator); } 

private:
    std::mt19937 generator;
    std::uniform_real_distribution<> double_dist;
};

#endif