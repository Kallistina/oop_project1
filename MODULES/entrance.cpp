#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/entrance.h"

using std::string;
using namespace std;
int random (int low, int high);

entrance::entrance(int NSegs, int K, segment* pointer, int node_) 
    : num_of_tolls(0), pointer_to_segment(pointer), num_of_vehicles(0), node(node_) {

    int rand_num_of_employe_tolls =  rand() % 5 + 1;
    int rand_num_of_electronic_tolls = rand() % 5 + 1;
    num_of_tolls = rand_num_of_employe_tolls + rand_num_of_electronic_tolls;
    
    tolls = new toll*[num_of_tolls] ;

    for(int i=0; i<num_of_tolls; i++) {
        if(i % 2 == 0) {
            if(rand_num_of_employe_tolls>0){
                tolls[i] = new employe_toll(NSegs, K, node);
                rand_num_of_employe_tolls--;
            }
            else {
                tolls[i] = new electronic_toll(NSegs, K, node);
                rand_num_of_electronic_tolls--;
            }
        }
        else {
            if(rand_num_of_electronic_tolls>0){
                tolls[i] = new electronic_toll(NSegs, K, node);
                rand_num_of_electronic_tolls--;
            }
            else {
                tolls[i] = new employe_toll(NSegs, K, node);
                rand_num_of_employe_tolls--;
            }
        }
        tolls[i]->set_speed(K);
        num_of_vehicles+=tolls[i]->get_num_of_vehicles();
    }  
}

int entrance::operate(int NSegs, int K){
//sub --- enter to the segment from entrance
    int vehicles_to_enter_counter=0;
    int employe_tolls_limit = K;
    int electronic_tolls_limit = 2*K;

    if(num_of_vehicles==0) {
        //add rand vehicles in entrance's tolls
        for(int i=0; i<num_of_tolls; i++) 
            for(int j=0; j<rand() % 3 + 1; j++){
                vehicle v(random(node, NSegs));
                v.set_current_segment(node);
                tolls[i]->add(v);
                num_of_vehicles++;
        }
    }

    while (pointer_to_segment->get_capacity() - pointer_to_segment->get_num_of_vehicles() > 0 && (employe_tolls_limit>0 || electronic_tolls_limit>0)) {
        for(int i=0; i<num_of_tolls; i++) {
            if( pointer_to_segment->get_capacity() - pointer_to_segment->get_num_of_vehicles() > 0 ) {
                if ( (tolls[i]->get_speed() == K && employe_tolls_limit>0) ||  (tolls[i]->get_speed() == 2*K && electronic_tolls_limit>0) ) {
                    pointer_to_segment->set_vehicle(pointer_to_segment->get_num_of_vehicles()-1, &tolls[i]->get_vehicle());
                    pointer_to_segment->get_vehicle(pointer_to_segment->get_num_of_vehicles()-1).set_exit_segment(false);
                    pointer_to_segment->set_num_of_vehicles(pointer_to_segment->get_num_of_vehicles()+1);
                    tolls[i]->sub();
                    num_of_vehicles--;
                    vehicles_to_enter_counter++;
                    //which limit should I reduce?
                    if(tolls[i]->get_speed() == K ) employe_tolls_limit--;
                    else electronic_tolls_limit--; 
                }
            }
            else break;
        }
        if(num_of_vehicles==0) {
        //add rand vehicles in entrance's tolls
        for(int i=0; i<num_of_tolls; i++) 
            for(int j=0; j<rand() % 3 + 1; j++){
                vehicle v(random(node, NSegs));
                v.set_current_segment(node);
                tolls[i]->add(v);
                num_of_vehicles++;
            }
        }
    }
//it's K time
    if(employe_tolls_limit==0 && electronic_tolls_limit==0) 
        K++;
    else
        K--;

    pointer_to_segment->set_K(K);

//add rand vehicles in entrance's tolls
    for(int i=0; i<num_of_tolls; i++) 
        for(int j=0; j<rand() % 3 + 1; j++){
            vehicle v(random(node, NSegs));
            v.set_current_segment(node);
            tolls[i]->add(v);
            num_of_vehicles++;
        }
    
    return vehicles_to_enter_counter;
}