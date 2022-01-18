#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

int random (int low, int high) {
    if (low > high)
        return high;
    return low + (rand() % (high - low));
}

vehicle::vehicle(int exit) : exit_node(exit), current_segment(-1), ready(false) {   
}

void vehicle::set_current_segment(int i) {
    current_segment=i;
}

bool vehicle::exit_attica() {
    if(exit_node==current_segment)
        return true;
    return false;
}

void vehicle::set_exit_segment(bool ready_) {
    ready=ready_;
}

bool vehicle::get_exit_segment() {
    return ready;
}