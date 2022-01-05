#pragma once 
#include <iostream>

using std::string;
using namespace std;

class entrance {
private:
    string node_name;
    int num_of_employe_tolls;
    int num_of_electronic_tolls;
public:
    entrance();
    void operate();
};