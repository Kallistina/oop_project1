#include <iostream>
#include <list>
#include "../INCLUDES/attica.h"
#include "../INCLUDES/segment.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0) {
    cout << "Attica Highway is in operation !!!" << endl;

    for(int i=0; i<NSegs; i++)
       segments.push_back(*(new segment(NSegs, K)));
}

void attica::operate() {
    std::list<segment>::iterator it;
    for (it = segments.end(); it != segments.begin(); --it){

    }


    
}



   // for(int i=segments.size(); i>0; i--){
    //     //  seg_i;
    //     // cout << "The number of vehicles of segment " << i << " is " << seg_i->veh << endl;
    //  }

// segment[i] = new segment()  
//segments.insert
//segments = new segment*[NSegs];