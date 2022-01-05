#pragma once 
#include <iostream>
#include "toll.h"
#include "vehicle.h"

using std::string;
using namespace std;

class entrance {
private:
    string node_name;
    toll employe_tolls[5];
    toll electronic_tolls[5];
public:
    entrance();
    void operate(int NSegs, int K);
};