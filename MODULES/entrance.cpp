#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/segment.h"
#include "../INCLUDES/toll.h"

using std::string;
using namespace std;

entrance::entrance(int NSegs, int K, segment* pointer, int node_) 
    : num_of_tolls(0), pointer_to_segment(pointer), num_of_vehicles(0), node(node_) {

    //srand(time(NULL));

    int rand_num_of_employe_tolls = rand() % 5 + 1;
    int rand_num_of_electronic_tolls = rand() % 5 + 1;
    num_of_tolls = rand_num_of_employe_tolls + rand_num_of_electronic_tolls;


    tolls = new toll*[num_of_tolls] ;

    for(int i=0; i<num_of_tolls; i++) {
        if(i % 2 == 0) {
            if(rand_num_of_employe_tolls>0){
                tolls[i] = new employe_toll(NSegs, K);
                rand_num_of_employe_tolls--;
            }
            else {
                tolls[i] = new electronic_toll(NSegs, K);
                rand_num_of_electronic_tolls--;
            }
        }
        else {
            if(rand_num_of_electronic_tolls>0){
                tolls[i] = new electronic_toll(NSegs, K);
                rand_num_of_electronic_tolls--;
            }
            else {
                tolls[i] = new employe_toll(NSegs, K);
                rand_num_of_employe_tolls--;
            }
        }
        tolls[i]->set_speed(K);
        num_of_vehicles+=tolls[i]->get_num_of_vehicles();
    }
}

int entrance::get_num_of_vehicles() {
    return num_of_vehicles;
}

int entrance::get_node() {
    return node;
}

int entrance::operate(int NSegs, int K){
//sub
    int vehicles_to_enter_counter=0;
    int employe_tolls_limit = K;
    int electronic_tolls_limit = 2*K;

   

    while (num_of_vehicles>0 && pointer_to_segment->get_capacity()>0 && (employe_tolls_limit>0 || electronic_tolls_limit>0)) {
        for(int i=0; i<num_of_tolls; i++) {
            if(pointer_to_segment->get_capacity()>0){
                if(tolls[i]->get_speed() == K && employe_tolls_limit>0) {
                    pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1] = &tolls[i]->get_vehicle();
                    pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1]->set_exit_segment(false);
                    pointer_to_segment->set_capacity(pointer_to_segment->get_capacity()-1);
                    pointer_to_segment->set_num_of_vehicles(pointer_to_segment->get_num_of_vehicles()-1);
                    tolls[i]->sub();
                    employe_tolls_limit--;
                    num_of_vehicles--;
                    vehicles_to_enter_counter++;
                }
                else if(electronic_tolls_limit>0) {
                    pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1] = &tolls[i]->get_vehicle();
                    pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1]->set_exit_segment(false);
                    pointer_to_segment->set_capacity(pointer_to_segment->get_capacity()-1);
                    pointer_to_segment->set_num_of_vehicles(pointer_to_segment->get_num_of_vehicles()-1);
                    tolls[i]->sub();
                    electronic_tolls_limit--;
                    vehicles_to_enter_counter++;
                }
            }
            else break;
        }
    }

    if(employe_tolls_limit==0 && employe_tolls_limit==0) 
        K++;
    else
        K--;

    pointer_to_segment->set_K(K);

//add
   // srand(time(NULL));
    for(int i=0; i<num_of_tolls; i++) {
        for(int j=0; j<rand() % 20 + 1; j++){
            vehicle v(rand() % NSegs + 1);
            tolls[i]->add(v);
            num_of_vehicles++;
        }
    }
    
    // for(int i=0; i<num_of_tolls; i++) {
    //     for(int j=0; j<tolls[i]->get_num_of_vehicles(); j++)
    //         num_of_vehicles++;
    // }

    cout << "NUMM" << num_of_vehicles << endl;

    return vehicles_to_enter_counter;
}
