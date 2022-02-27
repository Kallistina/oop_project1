#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    bool gone;
    bool ready;
public:
    vehicle(int exit);
    vehicle (const vehicle& copy_vehicle);
    void set_ready(bool ready_);
    bool get_ready();
    int get_exit_node();
    bool exit_segment();
    bool exit_attica(int current_segment);
    void time_to_go();
    bool is_gone();
};