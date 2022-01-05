#include <iostream>
#include "../INCLUDES/toll.h"
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

toll::toll(int NSegs) : num_of_vehicles(0){

    srand(time(NULL));
    vehicles = new vehicle*[100];
    int rand_num_of_vehicles = rand() % 20;

//create rand vehicles for toll initialization
    for(int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand() % NSegs);
    }
    num_of_vehicles=rand_num_of_vehicles;
}

void toll::add(vehicle* v){
    vehicles[num_of_vehicles] =  v;
    num_of_vehicles++;
}

void toll::sub(){
    num_of_vehicles--;
    vehicles[num_of_vehicles] =  NULL;
}