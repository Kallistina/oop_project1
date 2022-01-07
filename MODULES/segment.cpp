#include <iostream>
using namespace std;
#include "../INCLUDES/segment.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/vehicle.h" 

segment::segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer) 
    : seg_entrance(NSegs, K), previous(previous_seg), next(next_seg), pointer_to_attica(pointer), num_of_vehicles(0) {

    srand(time(NULL));

    capacity = rand() % 100 + 50;

    int rand_num_of_vehicles = rand() % 20 + 1;
    vehicles = new vehicle*[rand_num_of_vehicles];

    for (int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand() % NSegs + 1);
    }
}

void segment::enter(int NSegs, int K){
    // if (previous != -1) {
    //     int previous_segment_vehicles = pointer_to_attica->get_segment(previous)->num_of_vehicles;

    //     for(int i=0; i<previous_segment_vehicles; i++){
    //         if (num_of_vehicles<capacity){

    //          //tsekare mhpos einai null logv exit
    //             vehicles[num_of_vehicles] = pointer_to_attica->get_segment(previous)->vehicles[i];
    //             num_of_vehicles++;
    //         }
    //         else break;
    //     }
    // }
    // if(num_of_vehicles<capacity) 
    //     num_of_vehicles += seg_entrance.operate(NSegs, K, capacity);

    if (previous != -1) {
        int previous_segment_capacity = pointer_to_attica->get_segment(previous)->capacity;

        for(int i=0; i<previous_segment_capacity; i++){
            vehicle* current_vehicle =pointer_to_attica->get_segment(previous)->vehicles[i];
            if (num_of_vehicles<capacity){
                if(current_vehicle!=NULL){
                    for(int j=0; j<capacity; j++){
                        if(vehicles[j] == NULL) {
                            vehicles[j] = current_vehicle;
                            num_of_vehicles++;
                        }
                    }
                }
            }
            else break;
        }
    }
    if(num_of_vehicles<capacity) 
        num_of_vehicles += seg_entrance.operate(NSegs, K, capacity);
}

void segment::exit(){
    int copy_pointer=0;
    for(int i=0; i<num_of_vehicles; i++){
        if(vehicles[i]->ready_to_go()) {
            num_of_vehicles--;
            vehicles[i]=NULL;
        }
        else{         
            if (i!=copy_pointer){
                vehicles[copy_pointer]=vehicles[i];
                copy_pointer++;
                vehicles[i]=NULL;
            }
        }
    }
//ta antigrafoume se enan pinaka idias xoritikothtas
//diagrafoume ton palio, kratame ton kainourgio
}

void segment::pass(){
    for (int i=0; i<num_of_vehicles; i++){
        if (vehicles[num_of_vehicles-i]->ready_to_go()){
            int next_segment_capacity = pointer_to_attica->get_segment(next)->capacity;
            if (next_segment_capacity>0){
                //next has to be array, not an int
                //next->vehicles[next->num_of_vehicles]=vehicles[i];
                vehicles[i]=NULL;
                // next->num_of_vehicles++;
                next_segment_capacity--;
                num_of_vehicles--;
            }
                
        }
        // else{
        //     vehicles[k]=vehicles[i];
        //     k++;
        //     vehicles[i]=NULL;
        // }
    }
}

int segment::get_no_of_vehicles() {
    return num_of_vehicles;
}

void segment::operate(int percent){
    int num_of_readys = percent*num_of_vehicles/100;
    for (int i=0; i<num_of_readys && i<num_of_vehicles; i++){
        vehicles[i]->ready_to_go();
        // vehicles[i]->  get_destination
    }
}

  //char x=rand()%max;