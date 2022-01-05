#include <iostream>
using namespace std;
#include "entrance.h"

class segment {
private:
    entrance seg_entrance;
    int num_of_vehicles;
    int max_vehicles;
    int* prev;
    int* next;

public:
    segment(int NSegs, int max);

    void enter(int, int);
    void exit();
    void pass();
    void get_no_of_vehicles();
    void operate();
};