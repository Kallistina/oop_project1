#include <iostream>
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/segment.h"
#include "../INCLUDES/toll.h"

using std::string;
using namespace std;

entrance::entrance(int NSegs, int K, segment* pointer) 
    : node(-1), num_of_tolls(0), pointer_to_segment(pointer), num_of_vehicles(0) {

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

int entrance::operate(int NSegs, int K, int Capacity){
//sub
    int vehicles_to_enter_counter=0;
    int employe_tolls_limit = K;
    int electronic_tolls_limit = 2*K;

    while (Capacity!=0 && (employe_tolls_limit==0 || employe_tolls_limit==0))
    {
        for(int i=0; i<num_of_tolls; i++) {
            if(Capacity>0){
                if(tolls[i]->get_speed() == K){
                    if(employe_tolls_limit>0){
                        pointer_to_segment->vehicles[pointer_to_segment->get_no_of_vehicles()-1];
                        tolls[i]->sub();
                        employe_tolls_limit--;
                        Capacity--;
                        vehicles_to_enter_counter++;
                    }
                }
                else{
                    if(electronic_tolls_limit>0){
                        tolls[i]->sub();
                        electronic_tolls_limit--;
                        Capacity--;
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

    for(int i=0; i<num_of_tolls; i++)
        tolls[i]->set_speed(K);

//add
    srand(time(NULL));
    for(int i=0; i<num_of_tolls; i++) {
        for(int j=0; j<rand() % 20 + 1; j++){
            vehicle v(rand() % NSegs + 1);
            tolls[i]->add(v);
        }
    }
    
    for(int i=0; i<num_of_tolls; i++) {
        for(int j=0; j<tolls[i]->num_of_vehicles; j++)
            num_of_vehicles++;
    }
    return vehicles_to_enter_counter;
}


    // for(int i=0; i<5; i++){
    //     for(int j=0; j<K; j++){
    //         employe_tolls[i].sub();
    //     }
    //      for(int j=0; j<2*K; j++){
    //         electronic_tolls[i].sub();
    //     }
    // }



 // for(int i=0; i<5; i++){
    //     for(int j=0; j<rand() % 20; j++){
    //         vehicle v(rand() % NSegs);
    //         employe_tolls[i].add(&v);
    //     }
    //     for(int j=0; j<rand() % 20; j++){
    //         vehicle v(rand() % NSegs);
    //         electronic_tolls[i].add(&v);
    //     }
    // }