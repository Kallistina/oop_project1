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
    segment* get_segment(int i) { return segments[i]; }
    void operate(int Percent);
    void set_K(int K) { Kappa=K; }
    void set_vehicles(int i) { num_of_vehicles += i; }
};