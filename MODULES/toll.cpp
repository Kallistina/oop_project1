#include <iostream>
#include "../INCLUDES/toll.h"
#include "../INCLUDES/vehicle.h"

using std::string;
using namespace std;

toll::toll(int NSegs) {

    srand(time(NULL));
    int rand_num_of_vehicles = rand() % 20;
//create rand vehicles for toll initialization
    for(int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand()%NSegs);
    }
}

void toll::add(){

}

void toll::sub(){

}