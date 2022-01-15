#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    int current_segment;
    bool ready;
public:
    vehicle(int exit);
    void set_current_segment(int i);
    bool exit_attica();
    void set_exit_segment(bool ready_);
    bool get_exit_segment();
};


//feygei apo to tmhma --- flase !!
// synarthsh gia to K