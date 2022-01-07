#include <iostream>
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

vehicle::vehicle(int exit) : exit_node(exit), current_segment(-1), exit_segment(false) {   
}

void vehicle::set_current_segment(int i) {
    current_segment=i;
}

bool vehicle::exit_attica() {
    if(exit_node==current_segment)
        return true;
    return false;
}

bool vehicle::set_exit_segment(bool ready) {
    exit_segment=ready;
}