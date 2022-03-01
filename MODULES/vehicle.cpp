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

vehicle::vehicle(int exit) : exit_node(exit), ready(false), gone(false) {  } 

vehicle::vehicle(const vehicle& copy_vehicle) {
    this->exit_node = copy_vehicle.exit_node;
    this->ready = copy_vehicle.ready;
}

bool vehicle::get_ready() { return ready; }

void vehicle::set_ready(bool ready_) { ready=ready_; }

int vehicle::get_exit_node() { return exit_node; }   

bool vehicle::exit_attica(int current_segment) {
    if(exit_node==current_segment) return true;    
    return false;
}

void vehicle::time_to_go() { gone=true; }

bool vehicle::is_gone() {  return gone; }