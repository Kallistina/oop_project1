#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    int current_segment;
    bool ready_to_go;
public:
    vehicle(int exit);
};