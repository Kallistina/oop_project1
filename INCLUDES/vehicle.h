#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    int current_segment;
public:
    bool exit_segment;
    vehicle(int exit);
    void set_current_segment(int i);
    //bool set_exit_segment(bool ready);
    bool exit_attica();
};

//το νεχτ πρεπει να εχει εναν μετρητη κ και τον δικο του πινακα