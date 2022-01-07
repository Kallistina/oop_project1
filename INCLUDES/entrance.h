#pragma once 
#include <iostream>
#include "toll.h"
#include "vehicle.h"
#include "segment.h"

using std::string;
using namespace std;

class toll;
class segment;

class entrance {
private:
    int num_of_tolls;
    toll** tolls;  
    segment* pointer_to_segment;
public:
    int node;
    int num_of_vehicles;
    entrance(int NSegs, int K, segment* pointer);
    int operate(int NSegs, int K, int Capacity);
};
