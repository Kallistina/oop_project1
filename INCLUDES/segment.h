#pragma once
#include <iostream>
#include <list>
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
    attica* pointer_to_attica;
    entrance* seg_entrance;
    int Kappa;
public:
    vehicle** vehicles;
    segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer, int node);
    int enter(int NSegs);
    void exit();
    void pass(int i);
    void operate(int NSegs, int K, int Percent);
    void set_K(int K);
    int get_num_of_vehicles() { return num_of_vehicles; }

    void set_num_of_vehicles(int num) {  num_of_vehicles=num; }

    int get_capacity() { return capacity; }

    void set_capacity(int cap) { capacity=cap; }
};