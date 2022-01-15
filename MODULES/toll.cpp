#include <iostream>
#include <queue>
#include "../INCLUDES/toll.h"
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;


toll::toll(int NSegs, int K) : num_of_vehicles(0), speed(K) {

    srand(time(NULL));
    num_of_vehicles=rand() % 20;

//create rand vehicles for toll initialization
    for(int i=0; i<num_of_vehicles; i++){
        vehicle v(rand() % NSegs);
        vehicles.push(v);
    }
}

int toll::get_num_of_vehicles() {
    return num_of_vehicles;
}

void toll::add(vehicle v){
    vehicles.push(v);
}

void toll::sub(){
    vehicles.pop();
}

vehicle& toll::get_vehicle(){
    return vehicles.front();
}

int toll::get_speed(){
    return speed;
}

employe_toll::employe_toll(int NSegs, int K) : toll(NSegs, K)  {
}

void employe_toll::set_speed(int K){
    speed = K;
}

electronic_toll::electronic_toll(int NSegs, int K) : toll(NSegs, K) {
}

void electronic_toll::set_speed(int K){
    speed = 2*K;
}