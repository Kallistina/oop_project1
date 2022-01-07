#pragma once 
#include <iostream>

using std::string;
using namespace std;

class vehicle {
private:
    int exit_node;
    int current_segment;
    //bool ready_to_go;
public:
    vehicle(int exit);
    void set_current_segment(int i);
    //int get_current_segment();
    bool ready_to_go();
};

//το νεχτ πρεπει να εχει εναν μετρητη κ και τον δικο του πινακα