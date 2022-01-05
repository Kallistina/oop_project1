#include <iostream>
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

vehicle::vehicle(int exit) : exit_node(exit), current_segment(-1), ready_to_go(false){   
    cout << "this is a vehicle" << endl;
}

bool vehicle::check_to_go() {
    if(ready_to_go == current_segment)
        return true;
    else 
        return false;
}