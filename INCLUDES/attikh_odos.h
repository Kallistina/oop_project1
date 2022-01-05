#pragma once 
#include <iostream>

class attica{
private:
    const int num_of_segments;
    int num_of_vehicles;
public:
    attica(const int NSegs, int vehicles);
    void operate();
};


