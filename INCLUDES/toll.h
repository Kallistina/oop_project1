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
    int speed;
public:
    int num_of_vehicles;
    toll(int NSegs, int K);
    void add(vehicle v);
    void sub();
    virtual void set_speed(int K)=0;
    virtual int get_speed()=0;
};

class employe_toll : public toll {
public:  
    employe_toll(int NSegs, int K);
    void set_speed(int K);
    int get_speed();
};

class electronic_toll : public toll {
public:
    electronic_toll(int NSegs, int K);
    void set_speed(int K);
    int get_speed();
};