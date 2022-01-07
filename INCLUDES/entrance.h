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
    int operate(int NSegs, int K, int Capacity);
};
