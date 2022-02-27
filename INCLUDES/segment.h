#pragma once
#include <iostream>
#include "attica.h"
#include "entrance.h"

using namespace std;

class attica;
class entrance;

class segment {
private:
    int num_of_vehicles;
    int capacity;
    int previous;
    int next;
    int Kappa;
    attica* pointer_to_attica;
    entrance* seg_entrance;
    vehicle** vehicles;
public:
    segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer, int node);
    ~segment();
    int enter(int NSegs);
    void exit();
    bool pass(int Percent);
    void operate(int NSegs, int K, int Percent);
    void set_K(int K);
    void rebuild();
    vehicle get_vehicle(int i) { return *vehicles[i]; }
    void set_vehicle(int i, vehicle* veh ) { vehicles[i] = veh; }
    int get_num_of_vehicles() { return num_of_vehicles; }
    void set_num_of_vehicles(int num) {  num_of_vehicles=num; }
    int get_capacity() { return capacity; }
    void set_capacity(int cap) { capacity=cap; }
};