#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/attica.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0), Kappa(K), num_of_segments(NSegs) {
    cout << "Attica Highway is in operation !!!" << endl;

    segments = new segment*[NSegs];

    for(int i=0; i<NSegs; i++){
        if(i==0)
            segments[i] = new segment(NSegs, Kappa, -1, i+1, this, i);
        else if(i==NSegs-1)
            segments[i] = new segment(NSegs, Kappa, i-1, -1, this, i);
        else
            segments[i] = new segment(NSegs, Kappa, i-1, i+1, this, i);

        num_of_vehicles+=segments[i]->get_num_of_vehicles();
    }
}

attica::~attica() {
    for(int i=0; i<num_of_segments; i++)
        delete segments[i];
    delete segments;
}

void attica::operate(int NSegs, int Percent) {
    for(int i=NSegs-1; i>=0; i--) {
        segments[i]->operate(NSegs, Kappa, Percent);
        cout << "Number of vehicles in Segment " << i << " : " << segments[i]->get_num_of_vehicles() << endl;
    }
    cout << "Number of vehicles in Attica Highway : " << num_of_vehicles << endl;
}