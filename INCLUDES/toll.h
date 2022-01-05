#pragma once 
#include <iostream>
#include "vehicle.h"

using std::string;
using namespace std;

class toll {
private:
    vehicle** vehicles;
    int num_of_vehicles;
public:
    toll(int NSegs);
    void add(vehicle* v);
    void sub();
};