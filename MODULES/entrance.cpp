#include <iostream>
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/segment.h"
#include "../INCLUDES/toll.h"

using std::string;
using namespace std;

entrance::entrance(int NSegs, int K, segment* pointer, int node_) 
    : num_of_tolls(0), pointer_to_segment(pointer), num_of_vehicles(0), node(node_) {

    srand(time(NULL));

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
    }
}

int entrance::get_num_of_vehicles() {
    return num_of_vehicles;
}

int entrance::get_node() {
    return node;
}

// void entrance::set_node(int i) {
//     node=i;
// }

int entrance::operate(int NSegs, int K, int Capacity){
//sub
    int vehicles_to_enter_counter=0;
    int employe_tolls_limit = K;
    int electronic_tolls_limit = 2*K;

    while (Capacity>0 && (employe_tolls_limit==0 || employe_tolls_limit==0))
    {
        for(int i=0; i<num_of_tolls; i++) {
            if(Capacity>0){
                if(tolls[i]->get_speed() == K){
                    if(employe_tolls_limit>0){
                        pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1] = &tolls[i]->get_vehicle();
                        pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1]->set_exit_segment(false);
                        Capacity--;
                        pointer_to_segment->set_num_of_vehicles(pointer_to_segment->get_num_of_vehicles()-1);
                        tolls[i]->sub();
                        employe_tolls_limit--;
                        vehicles_to_enter_counter++;
                    }
                }
                else{
                    if(electronic_tolls_limit>0){
                        pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1] = &tolls[i]->get_vehicle();
                        pointer_to_segment->vehicles[pointer_to_segment->get_num_of_vehicles()-1]->set_exit_segment(false);
                        Capacity--;
                        pointer_to_segment->set_num_of_vehicles(pointer_to_segment->get_num_of_vehicles()-1);
                        tolls[i]->sub();
                        electronic_tolls_limit--;
                        vehicles_to_enter_counter++;
                    }
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

    // for(int i=0; i<num_of_tolls; i++)
    //     tolls[i]->set_speed(K);
//add
    srand(time(NULL));
    for(int i=0; i<num_of_tolls; i++) {
        for(int j=0; j<rand() % 20 + 1; j++){
            vehicle v(rand() % NSegs + 1);
            tolls[i]->add(v);
        }
    }
    
    for(int i=0; i<num_of_tolls; i++) {
        for(int j=0; j<tolls[i]->get_num_of_vehicles(); j++)
            num_of_vehicles++;
    }
    return vehicles_to_enter_counter;
}
