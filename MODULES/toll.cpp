#include <iostream>
#include <queue>
#include "../INCLUDES/toll.h"
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;


toll::toll(int NSegs) : num_of_vehicles(0){

    srand(time(NULL));
    num_of_vehicles=rand() % 20;

//create rand vehicles for toll initialization
    for(int i=0; i<num_of_vehicles; i++){
        vehicle v(rand() % NSegs);
        vehicles.push(v);
    }
}

void toll::add(vehicle v){
    vehicles.push(v);
    num_of_vehicles = vehicles.size();
    
}

void toll::sub(){
    vehicles.pop();
    num_of_vehicles = vehicles.size();
}



// vehicles[i] = new vehicle(rand() % NSegs);   
//    // vehicles = new vehicle*[100];
//     int rand_num_of_vehicles = rand() % 20;

//vehicles[num_of_vehicles] =  v; 


//vehicles[num_of_vehicles] =  NULL;