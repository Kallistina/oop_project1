#include <iostream>
#include "../INCLUDES/attikh_odos.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int vehicles) : num_of_vehicles(vehicles) {
    cout << "Αυτοκινητόδρομος σε λειτουργία" << endl;

    segments = new segment*[NSegs];
    for(int i=0; i<NSegs; i++){
       // segment[i] = new segment()
    }
}

void attica::operate(int NSegs) {

    for(int i=NSegs; i>0; i--){
        //  seg_i;
        // cout << "The number of vehicles of segment " << i << " is " << seg_i->veh << endl;
     }
    
}