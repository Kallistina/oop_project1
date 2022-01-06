#pragma once 
#include <iostream>
#include <queue>
#include "vehicle.h"

using std::string;
using namespace std;

class toll {
private:
    queue <vehicle> vehicles;
    int num_of_vehicles;
public:
    toll(int NSegs);
    void add(vehicle v);
    void sub();
};