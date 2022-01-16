#pragma once 
#include <iostream>
#include <list>
#include "segment.h"

using namespace std;
using namespace std;

class segment;

class attica{
private:
    int num_of_vehicles;
    int Kappa;
    segment** segments;    
public:
    attica(int NSegs, int K);
    segment* get_segment(int i);
    void set_K(int K);
    void operate(int NSegs, int Percent);
};


