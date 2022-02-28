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

entrance::~entrance() {
    for(int i=0; i<num_of_tolls; i++)
        delete tolls[i];
    delete tolls;
}

int entrance::operate(int NSegs, int K){
//sub --- enter to the segment from entrance
    int vehicles_to_enter_counter=0;
    int employe_tolls_limit = K;
    int electronic_tolls_limit = 2*K;

    if(num_of_vehicles==0) {      //add rand vehicles in entrance's tolls
        for(int i=0; i<num_of_tolls; i++) 
            for(int j=0; j<rand() % 3 + 1; j++){
                tolls[i]->add(vehicle(random(node, NSegs)));
                num_of_vehicles++;
        }
    }

    while (pointer_to_segment->get_capacity() > pointer_to_segment->get_num_of_vehicles() && (employe_tolls_limit>0 || electronic_tolls_limit>0)) {
        //cout << "tolll" << K << endl;
        for(int i=0; i<num_of_tolls; i++) {
            if( pointer_to_segment->get_capacity() >  pointer_to_segment->get_num_of_vehicles()) {
                if ( (tolls[i]->get_speed() == K && employe_tolls_limit>0) ||  (tolls[i]->get_speed() == 2*K && electronic_tolls_limit>0) ) {
                    pointer_to_segment->set_vehicle(pointer_to_segment->get_num_of_vehicles(), &tolls[i]->get_vehicle());
                    tolls[i]->sub();
                    num_of_vehicles--;
                    vehicles_to_enter_counter++;
                    if(tolls[i]->get_speed() == K ) employe_tolls_limit--;      //which limit should I reduce?
                    else electronic_tolls_limit--; 
 //cout << "tollkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkl" << endl;
                }
               
            }
            else break;
        }
        if(num_of_vehicles==0) {  //add rand vehicles in entrance's tolls
            for(int i=0; i<num_of_tolls; i++) 
                for(int j=0; j<rand() % 3 + 1; j++){
                    tolls[i]->add(vehicle(random(node, NSegs)));
                    num_of_vehicles++;
            }
        }
    }
//it's K time
    if(employe_tolls_limit==0 && electronic_tolls_limit==0)  K++;
    else if(K!=1) K--;

    for(int i=0; i<num_of_tolls; i++)
        tolls[i]->set_speed(K);

        
    pointer_to_segment->set_K(K);

    for(int i=0; i<num_of_tolls; i++) //add rand vehicles in entrance's tolls
        for(int j=0; j<rand() % 3 + 1; j++){
            tolls[i]->add(vehicle(random(node, NSegs)));
            num_of_vehicles++;
        }
    
    return vehicles_to_enter_counter;
}