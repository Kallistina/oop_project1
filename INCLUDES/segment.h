#include <iostream>
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
public:
    segment(int NSegs, int K);
    void enter(int, int);
    void exit();
    void pass();
    void get_no_of_vehicles();
    void operate();
};