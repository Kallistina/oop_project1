#pragma once
#include <iostream>
#include <list>
#include "attica.h"
#include "entrance.h"
#include "vehicle.h"

using namespace std;

class attica;
class entrance;

class segment {
private:
    int capacity;
    int previous;
    int next;
    attica* pointer_to_attica;
    int num_of_vehicles;
public:
    vehicle** vehicles;
    entrance seg_entrance;
    segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer);
    int enter(int NSegs, int K);
    void exit();
    void pass(int i);
    int get_no_of_vehicles();
    void operate(int NSegs, int K, int Percent);
};