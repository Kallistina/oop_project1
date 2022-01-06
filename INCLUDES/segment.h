#include <iostream>
#include <list>
#include "attica.h"
#include "entrance.h"
#include "vehicle.h"

using namespace std;

class segment {
private:
    entrance seg_entrance;
    vehicle** vehicles;
    int capacity;
    int previous;
    int next;
    attica* pointer_to_attica;
    int num_of_vehicles;
public:
    segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer);
    void enter(int NSegs, int K);
    void exit();
    void pass();
    void get_no_of_vehicles();
    void operate();
};