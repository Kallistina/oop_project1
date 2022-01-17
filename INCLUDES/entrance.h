#pragma once 
#include <iostream>
#include "toll.h"
#include "vehicle.h"
#include "segment.h"

using std::string;
using namespace std;

class toll;
class segment;

class entrance {
private:
    int num_of_tolls;
    int num_of_vehicles;
    int node;
    toll** tolls;  
    segment* pointer_to_segment;
public:  
    entrance(int NSegs, int K, segment* pointer, int node_);
    int get_num_of_vehicles();
    int get_node();
   // void set_node(int i);
    int operate(int NSegs, int K);
};
