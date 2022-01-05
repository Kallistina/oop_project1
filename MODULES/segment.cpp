#include <iostream>
using namespace std;
#include "INCLUDES/segment.h"
#include "INCLUDES/vehicle.h"

segment::segment(int NSegs, int max){
    srand(time(NULL));
    char x=rand()%max;
    for (int i=0; i<x; i++){
        vehicle v(rand()%NSegs);
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