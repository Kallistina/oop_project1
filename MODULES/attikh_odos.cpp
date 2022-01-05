#include <iostream>
#include "../INCLUDES/attikh_odos.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int vehicles) : num_of_segments(NSegs), num_of_vehicles(vehicles) {
    cout << "Αυτοκινητόδρομος σε λειτουργία" << endl;
}

void attica::operate() {

    for(int i=num_of_segments; i>0; i--){
        //  seg_i;
        // cout << "The number of vehicles of segment " << i << " is " << seg_i->veh << endl;
     }
    
}
