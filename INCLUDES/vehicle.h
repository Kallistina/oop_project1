#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    int current_segment;
    bool exit_segment;
public:
    vehicle(int exit);
    void set_current_segment(int i);
    //int get_current_segment();
    bool exit_attica();
};

//το νεχτ πρεπει να εχει εναν μετρητη κ και τον δικο του πινακα