#pragma once 
#include <iostream>
#include <list>
#include "segment.h"

class segment;

class attica{
private:
   // list <segment> segments;
    segment** segments;
    int num_of_vehicles;
public:
    attica(int NSegs, int K);
    void operate(int NSegs,int K, int Percent);
    segment* get_segment(int i);
};


