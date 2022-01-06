#include <iostream>
#include <queue>
#include "../INCLUDES/toll.h"
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;


// toll::toll(int NSegs, int K) : num_of_vehicles(0), speed(K) {

//     srand(time(NULL));
//     num_of_vehicles=rand() % 20;

// //create rand vehicles for toll initialization
//     for(int i=0; i<num_of_vehicles; i++){
//         vehicle v(rand() % NSegs);
//         vehicles.push(v);
//     }
// }

employe_toll::employe_toll(int NSegs, int K)  {
    srand(time(NULL));
   // num_of_vehicles=rand() % 20;
   speed = K;

//create rand vehicles for toll initialization
    for(int i=0; i<rand() % 20; i++){
        vehicle v(rand() % NSegs);
        vehicles.push(v);
    }

}

electronic_toll::electronic_toll(int NSegs, int K) {
    srand(time(NULL));
   // num_of_vehicles=rand() % 20;
    speed = 2*K;

//create rand vehicles for toll initialization
    for(int i=0; i<rand() % 20; i++){
        vehicle v(rand() % NSegs);
        vehicles.push(v);
    }
}

void toll::add(vehicle v){
    vehicles.push(v);
   // num_of_vehicles = vehicles.size();
    
}

void toll::sub(){
    vehicles.pop();
   // num_of_vehicles = vehicles.size();
}

int toll::get_speed(){
    return speed;
}



// int employe_toll::get_speed(){
//     return speed;
// }

// int electronic_toll::get_speed(){
//     return speed;
// }










// vehicles[i] = new vehicle(rand() % NSegs);   
//    // vehicles = new vehicle*[100];
//     int rand_num_of_vehicles = rand() % 20;

//vehicles[num_of_vehicles] =  v; 


//vehicles[num_of_vehicles] =  NULL;