#include <iostream>
using namespace std;
#include "../INCLUDES/segment.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/vehicle.h" 

segment::segment(int NSegs, int K) : seg_entrance(NSegs, K) {
    srand(time(NULL));

    capacity = rand() % 100 + 50;
    previous
    next
    
    int rand_num_of_vehicles = rand() % 20 + 1;
    vehicles = new vehicle*[rand_num_of_vehicles];

    for (int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand() % NSegs + 1);
    }
}

void segment::pass(){
    for (int i=0; i<num_of_vehicles; i++){
        if (vehicles[num_of_vehicles-i]->check_to_go() )
    }
}

void segment::enter(int num_of_vehicles, int max_vehicles){

    if (num_of_vehicles<max_vehicles){
        num_of_vehicles++;
    }
}

void segment::operate(){

}

  //char x=rand()%max;