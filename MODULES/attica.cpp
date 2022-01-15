#include <iostream>
#include <list>
#include "../INCLUDES/attica.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/segment.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0) {
    cout << "Attica Highway is in operation !!!" << endl;

   segments = new segment*[NSegs];

    for(int i=0; i<NSegs; i++){
        if(i==0){
            segments[i] = new segment(NSegs, K, -1, i+1, this);
            segments[i]->seg_entrance->set_node(i);
        }
        else if(i==NSegs-1){
            segments[i] = new segment(NSegs, K, i-1, -1, this);
        }
        else{
            segments[i] = new segment(NSegs, K, i-1, i+1, this);
        }
    }    
}

void attica::operate(int NSegs,int K, int Percent) {
    for(int i=NSegs; i>0; i--) {
        segments[i]->operate(NSegs, K,Percent);
        num_of_vehicles += segments[i]->get_no_of_vehicles();
        cout << "Number of Attica Highway vehicles: " << num_of_vehicles << endl;
        //cout << "Number of Segment" << i << " vehicles: " << segments[i]->get_no_of_vehicles() << endl;
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