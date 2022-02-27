#pragma once 
#include <iostream>
#include "segment.h"

using namespace std;

class segment;

class attica{
private:
    int num_of_vehicles;
    int num_of_segments;
    int Kappa;
    segment** segments;    
public:
    attica(int NSegs, int K);
    ~attica();
    void operate(int NSegs, int Percent);
    segment* get_segment(int i) { return segments[i]; }
    void set_K(int K) { Kappa=K; }
    void set_vehicles(int i) { num_of_vehicles += i; }
};