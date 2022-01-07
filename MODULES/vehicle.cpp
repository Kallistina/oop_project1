#include <iostream>
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

vehicle::vehicle(int exit) : exit_node(exit), current_segment(-1) {   
}

void vehicle::set_current_segment(int i) {
    current_segment=i;
}

bool vehicle::ready_to_go() {
    if(exit_node==current_segment)
        return true;
    return false;
}