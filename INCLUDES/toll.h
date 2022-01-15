#pragma once 
#include <iostream>
#include <queue>
#include "vehicle.h"

using std::string;
using namespace std;
using std::queue;

class vehicle;

class toll {
protected:
    queue <vehicle> vehicles;
    int num_of_vehicles;
    int speed;
public:
    toll(int NSegs, int K);
    int get_num_of_vehicles();
    void add(vehicle v);
    void sub();
    vehicle& get_vehicle();
    int get_speed();
    virtual void set_speed(int K)=0;
};

class employe_toll : public toll {
public:  
    employe_toll(int NSegs, int K);
    void set_speed(int K);
};

class electronic_toll : public toll {
public:
    electronic_toll(int NSegs, int K);
    void set_speed(int K);
};