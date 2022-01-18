#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/toll.h"

using std::string;
using namespace std;
int random (int low, int high);

/////////////////////////////// TOLL ///////////////////////////////////
toll::toll(int NSegs, int K, int Segment_i) : num_of_vehicles(0), speed(K) {

    srand(time(NULL));
    num_of_vehicles=rand() % 3 + 1;

//create rand vehicles for toll initialization
    for(int i=0; i<num_of_vehicles; i++){
        vehicle v(random(Segment_i, NSegs));
        v.set_current_segment(Segment_i);
        vehicles.push(v);
    }
}

int toll::get_num_of_vehicles() {
    return num_of_vehicles;
}

int toll::get_speed(){
    return speed;
}

vehicle& toll::get_vehicle(){
    return vehicles.front();
}

void toll::add(vehicle v){
    vehicles.push(v);
}

void toll::sub(){
    vehicles.pop();
}

/////////////////////////////// EMPLOYE TOLL ///////////////////////////////////
employe_toll::employe_toll(int NSegs, int K, int Segment_i) : toll(NSegs, K, Segment_i)  {
    set_speed(K);
}

void employe_toll::set_speed(int K){
    speed = K;
}

/////////////////////////////// ELECTRONIC TOLL ///////////////////////////////////
electronic_toll::electronic_toll(int NSegs, int K, int Segment_i) : toll(NSegs, K, Segment_i) {
    set_speed(K);
}

void electronic_toll::set_speed(int K){
    speed = 2*K;
}