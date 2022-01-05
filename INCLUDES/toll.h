#pragma once 
#include <iostream>
#include "vehicle.h"

using std::string;
using namespace std;

class toll {
private:
    vehicle vehicles[100];
public:
    toll(int NSegs);
    void add();
    void sub();
};