#include <iostream>
#include <list>
#include "../INCLUDES/attica.h"
#include "../INCLUDES/segment.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0) {
    cout << "Attica Highway is in operation !!!" << endl;

   segments = new segment*[NSegs];

    for(int i=0; i<NSegs; i++){
        if(i==0){
            segments[i] = new segment(NSegs, K, NULL, i+1, this);
        }
        else if(i==NSegs-1){
            segments[i] = new segment(NSegs, K, i-1, NULL, this);
        }
        else{
            segments[i] = new segment(NSegs, K, i-1, i+1, this);
        }
    }    
}

void attica::operate(int NSegs) {
    for(int i=NSegs; i>0; i--) {

    }

    
}

segment* attica::get_segment(int i){
    return segments[i];
}



    // list<segment>::iterator it;
    // // for (it = segments.end(); it != segments.begin(); --it){

    // // }

    //list<segment>::iterator it=segments.begin();
   // auto it=segments.begin();


//    for(int i=0; i<NSegs; i++) {
//        segments[i] = new segment(NSegs, K, i);
//    }

    // for(int i=0; i<NSegs; i++){
    //     if(i==0){
    //         segments.push_back(*(new segment(NSegs, K, it)));
    //     }
    //     else if(i==NSegs-1){
    //         segments.push_back(*(new segment(NSegs, K, it)));
    //     }
    //     else{
    //         segments.push_back(*(new segment(NSegs, K, it)));
    //     }
    // }

   // for(int i=segments.size(); i>0; i--){
    //     //  seg_i;
    //     // cout << "The number of vehicles of segment " << i << " is " << seg_i->veh << endl;
    //  }

// segment[i] = new segment()  
//segments.insert
//segments = new segment*[NSegs];