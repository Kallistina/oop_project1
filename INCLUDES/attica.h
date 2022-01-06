#pragma once 
#include <iostream>
#include <list>
#include "segment.h"

class attica{
private:
    list <segment> segments;
    int num_of_vehicles;
public:
    attica(int NSegs, int K);
    void operate();
};


