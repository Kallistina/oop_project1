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
    int Kappa;
public:
    toll(int NSegs, int K, int Segment_i);
   ~toll();
    int get_num_of_vehicles();
    int get_Kappa();
    vehicle& get_vehicle();
    virtual void set_Kappa(int K)=0;
    void add(vehicle v);
    void sub();
};

class employe_toll : public toll {
public:  
    employe_toll(int NSegs, int K, int Segment_i);
    void set_Kappa(int K);
};

class electronic_toll : public toll {
public:
    electronic_toll(int NSegs, int K, int Segment_i);
    void set_Kappa(int K);
};