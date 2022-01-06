#pragma once 
#include <iostream>
#include "toll.h"
#include "vehicle.h"

using std::string;
using namespace std;

class entrance {
private:
    int node;
    int num_of_tolls;
    toll** tolls;  
public:
    entrance(int NSegs, int K);
    void operate(int NSegs, int K, int Capacity);
};

// toll employe_tolls[3];
// toll electronic_tolls[3];