#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "../INCLUDES/attica.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/segment.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0), Kappa(K) {
    cout << "Attica Highway is in operation !!!" << endl;

   segments = new segment*[NSegs];

    for(int i=0; i<NSegs; i++){
        if(i==0){
            segments[i] = new segment(NSegs, Kappa, -1, i+1, this, i);
            //segments[i]->seg_entrance->set_node(i);
        }
        else if(i==NSegs-1){
            segments[i] = new segment(NSegs, Kappa, i-1, -1, this, i);
        }
        else{
            segments[i] = new segment(NSegs, Kappa, i-1, i+1, this, i);
        }
    }    
}

segment* attica::get_segment(int i){
    return segments[i];
}

void attica::set_K(int K) {
    Kappa=K;
}

void attica::operate(int NSegs, int Percent) {
    for(int i=NSegs-1; i>=0; i--) {
           cout << i << endl;
        segments[i]->operate(NSegs, Kappa, Percent);
        num_of_vehicles += segments[i]->get_num_of_vehicles();
        cout << "Number of Attica Highway vehicles: " << num_of_vehicles << endl;
        //cout << "Number of Segment" << i << " vehicles: " << segments[i]->get_no_of_vehicles() << endl;
    }
}



