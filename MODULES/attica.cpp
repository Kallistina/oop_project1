#include <iostream>
#include <list>
#include "../INCLUDES/attica.h"

using std::string;
using namespace std;

attica::attica(const int NSegs) : num_of_vehicles(0) {
    cout << "Αυτοκινητόδρομος σε λειτουργία" << endl;

    //segments = new segment*[NSegs];
    for(int i=0; i<NSegs; i++){
       // segment[i] = new segment()
       segments.insert(i, segments.size(), new segment());
    }
}

void attica::operate() {

    for(int i=segments.size(); i>0; i--){
        //  seg_i;
        // cout << "The number of vehicles of segment " << i << " is " << seg_i->veh << endl;
     }
    
}