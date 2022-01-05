#pragma once 
#include <iostream>
#include "segment.h"

class attica{
private:
    segment** segments;
    int num_of_vehicles;
public:
    attica(const int NSegs, int vehicles);
    void operate(int NSegs);
};


