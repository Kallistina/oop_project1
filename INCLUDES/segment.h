#pragma once
#include <iostream>
#include "attica.h"
#include "entrance.h"

using namespace std;

class attica;
class entrance;

class segment {
private:
    entrance* seg_entrance;
    int num_of_vehicles;
    int capacity;
    int Kappa;
    attica* pointer_to_attica;
    vehicle** vehicles;
public:
    segment(int NSegs, int K, int node, attica* pointer);
    ~segment();
    int enter(int NSegs);
    void exit();
    bool pass(int Percent);
    void operate(int NSegs, int K, int Percent);
    void rebuild();
    void set_K(int K);
    vehicle get_vehicle(int i) { return *vehicles[i]; }
    void set_vehicle(int i, vehicle* veh ) { 
        delete vehicles[i]; 
        vehicles[i] = new vehicle(*veh);  
        vehicles[i]->set_ready(false); 
        num_of_vehicles++;
    }
    int get_num_of_vehicles() { return num_of_vehicles; }
    void set_num_of_vehicles(int num) {  num_of_vehicles+=num; }
    int get_capacity() { return capacity; }
};