#pragma once 
#include <iostream>
#include <queue>
#include "vehicle.h"

using std::string;
using namespace std;

class toll {
protected:
    queue <vehicle> vehicles;
    int num_of_vehicles;
    int speed;
public:
   // toll(int NSegs, int K);
    void add(vehicle v);
    void sub();
    int get_speed();
};

class employe_toll : public toll {
public:  
    employe_toll(int NSegs, int K);
  // int get_speed();
};

class electronic_toll : public toll {
public:
    electronic_toll(int NSegs, int K);
  //  int get_speed();
};