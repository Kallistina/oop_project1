#include <iostream>
using namespace std;
#include "../INCLUDES/segment.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/vehicle.h" 

segment::segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer) 
    : seg_entrance(NSegs, K, this), previous(previous_seg), next(next_seg), pointer_to_attica(pointer), num_of_vehicles(0) {

    srand(time(NULL));

    capacity = rand() % 100 + 50;

    int rand_num_of_vehicles = rand() % 20 + 1;
    vehicles = new vehicle*[rand_num_of_vehicles];

    for (int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand() % NSegs + 1);
    }
}

int segment::enter(int NSegs, int K){
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

    int enter_toll_vehicles=0;
    if(num_of_vehicles<capacity) {
        enter_toll_vehicles = seg_entrance.operate(NSegs, K, capacity);
        num_of_vehicles += enter_toll_vehicles;
    } 
        
    return enter_toll_vehicles;


    // while(num_of_vehicles<capacity) {
    //     vehicle* toll_vehicle = seg_entrance.operate(NSegs, K, capacity);
    //     if(toll_vehicle!=NULL) {
    //         vehicles[num_of_vehicles-1] = toll_vehicle;
    //         num_of_vehicles++;
    //         capacity--;
    //     }
    // }
}

void segment::exit(){
    if(previous!=-1){
       int copy_pointer=0;
        for(int i=0; i<num_of_vehicles; i++){
            if(vehicles[i]->exit_attica()) {
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
    }
    
//ta antigrafoume se enan pinaka idias xoritikothtas
//diagrafoume ton palio, kratame ton kainourgio
}

void segment::pass(int i){
    // for (int i=0; i<num_of_vehicles; i++){
    //     if (vehicles[num_of_vehicles-i]->ready_to_go()){
    //         int next_segment_capacity = pointer_to_attica->get_segment(next)->capacity;
    //         if (next_segment_capacity>0){
    //             //next has to be array, not an int
    //             //next->vehicles[next->num_of_vehicles]=vehicles[i];
    //             vehicles[i]=NULL;
    //             // next->num_of_vehicles++;
    //             next_segment_capacity--;
    //             num_of_vehicles--;
    //         }
                
    //     }
    //     // else{
    //     //     vehicles[k]=vehicles[i];
    //     //     k++;
    //     //     vehicles[i]=NULL;
    //     // }
    // }
    int next_segment_num_of_vehicles = pointer_to_attica->get_segment(next)->num_of_vehicles;
    pointer_to_attica->get_segment(next)->vehicles[next_segment_num_of_vehicles-1] = vehicles[i];
    next_segment_num_of_vehicles++;
    vehicles[i]->set_exit_segment(false);
    vehicles[i]=NULL;

}

int segment::get_no_of_vehicles() {
    return num_of_vehicles;
}

void segment::operate(int NSegs, int K, int Percent){

    exit();

    srand(time(NULL));
    int num_of_exit_segment = Percent*num_of_vehicles/100;
    int counter=0;
    while (counter!=num_of_exit_segment) {
        int rand_i = rand() % (num_of_vehicles-1) ;
        if(vehicles[rand_i]->exit_segment == false){
            vehicles[rand_i]->set_exit_segment(true);
            counter++;
        }
    }

    if(next!=-1) {
        bool flag=false;
        num_of_exit_segment=0;
        for(int i=0; i<num_of_vehicles; i++){
            if(vehicles[i]->exit_segment==true)
                num_of_exit_segment++;
        }
        if(pointer_to_attica->get_segment(next)->capacity >= num_of_exit_segment){
            for(int i=0; i<num_of_vehicles; i++)
                pass(i);
        }
        else{
            int num_of_exit_vehicles = num_of_exit_segment - pointer_to_attica->get_segment(next)->capacity;
            while (num_of_exit_vehicles>0) {
                int rand_i = rand() % (num_of_vehicles-1) ;
                if(vehicles[rand_i]->exit_segment == true){
                    pass(rand_i);
                    num_of_exit_vehicles--;
                }
            }
            flag=true;
        }

        int enter_toll_vehicles = enter(NSegs, K);  
        bool flag2=false;
        if(enter_toll_vehicles < seg_entrance.num_of_vehicles) {
            cout << "Delays in entrance of node " << seg_entrance.node << endl;
            flag2=true;
        } 
        if(flag) 
            cout << "Delays after the node " << seg_entrance.node << endl;
        if(flag==false && flag2==false)
            cout << "Keep a safe distance in the segment after the node " << seg_entrance.node << endl;
    }    
}

    // int num_of_readys = Percent*num_of_vehicles/100;
    // for (int i=0; i<num_of_readys && i<num_of_vehicles; i++){
    //     vehicles[i]->exit_attica();
    //     // vehicles[i]->  get_destination
    // }  