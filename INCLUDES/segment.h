#include <iostream>
using namespace std;
#include "INCLUDES/entrance.h"

class segmanet{
private:
    entrance seg_entrance;
    int num_of_vehicles;
    int max_vehicles;
    int* prev;
    int* next;

public:
    segmanet(int max){}

    void enter(int, int);
    void exit();
    void pass();
    void get_no_of_vehicles();
    void operate();
};