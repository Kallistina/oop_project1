#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/attica.h"

using std::string;
using namespace std;

attica::attica(const int NSegs, int K) : num_of_vehicles(0), Kappa(K), num_of_segments(NSegs) {
    cout << "Attica Highway is in operation !!!" << endl;
    cout << endl;
    segments = new segment*[num_of_segments];

    for(int i=0; i<num_of_segments; i++){
        segments[i] = new segment(num_of_segments, Kappa, i, this);
        num_of_vehicles+=segments[i]->get_num_of_vehicles();
    }
}

attica::~attica() {
    for(int i=0; i<num_of_segments; i++)
        delete segments[i];
    delete segments;
}

void attica::operate(int Percent) {
    for(int i=num_of_segments -1; i>=0; i--) {
        segments[i]->operate(num_of_segments, Kappa, Percent);
        cout << "Number of vehicles in Segment " << i << " : " << segments[i]->get_num_of_vehicles() << endl;
    }
    cout << "Number of vehicles in Attica Highway : " << num_of_vehicles << endl;
    cout << endl;
}