#include <iostream>
#include "../INCLUDES/segment.h"
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/vehicle.h" 

using namespace std;
using namespace std;

segment::segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer, int node) 
    :  previous(previous_seg), next(next_seg), pointer_to_attica(pointer), num_of_vehicles(0) {

    srand(time(NULL));

    seg_entrance = new entrance(NSegs, K, this, node);

    capacity = rand() % 100 + 50;

    int rand_num_of_vehicles = rand() % 20 + 1;
    vehicles = new vehicle*[rand_num_of_vehicles];

    for (int i=0; i<rand_num_of_vehicles; i++){
        vehicles[i] = new vehicle(rand() % NSegs + 1);
    }
}

int segment::get_num_of_vehicles() {
    return num_of_vehicles;
}

void segment::set_num_of_vehicles(int num) {
    num_of_vehicles=num;
}

void segment::set_K(int K) {
    Kappa=K;
    pointer_to_attica->set_K(Kappa);
}

int segment::enter(int NSegs){
    return seg_entrance->operate(NSegs, Kappa, capacity);
}

 
void segment::exit(){
    int copy_pointer=0;
    for(int i=0; i<num_of_vehicles; i++){
        if(vehicles[i]->exit_attica()) {
            num_of_vehicles--;
            vehicles[i]=NULL;
        }
        else{       
            if (i!=copy_pointer){
                vehicles[copy_pointer]=vehicles[i];
                vehicles[i]=NULL;
            }
            copy_pointer++; 
        }
    } 
}

void segment::pass(int i){
    int next_segment_num_of_vehicles = pointer_to_attica->get_segment(next)->num_of_vehicles;
    vehicles[i]->set_exit_segment(false);
    pointer_to_attica->get_segment(next)->vehicles[next_segment_num_of_vehicles-1] = vehicles[i];
    pointer_to_attica->get_segment(next)->set_num_of_vehicles(next_segment_num_of_vehicles+1);
    vehicles[i]=NULL;
}

void segment::operate(int NSegs, int K, int Percent){
//EXIT
    if(previous!=-1)
        exit();
//PASS
    srand(time(NULL));
    int num_of_exit_segment = Percent*num_of_vehicles/100;
    int counter=0;
    while (counter!=num_of_exit_segment) {
        int rand_i = rand() % num_of_vehicles ;
        if(vehicles[rand_i]->get_exit_segment() == false){
            vehicles[rand_i]->set_exit_segment(true);
            counter++;
        }
    }

    if(next!=-1) {
        bool flag=false;
        num_of_exit_segment=0;
        for(int i=0; i<num_of_vehicles; i++){
            if(vehicles[i]->get_exit_segment()==true)
                num_of_exit_segment++;
        }
        if(pointer_to_attica->get_segment(next)->capacity >= num_of_exit_segment){
            for(int i=0; i<num_of_vehicles; i++)
                if(vehicles[i]->get_exit_segment()==true)
                    pass(i);
        }
        else{
            int num_of_exit_vehicles = num_of_exit_segment - pointer_to_attica->get_segment(next)->capacity;
            while (num_of_exit_vehicles>0) {
                int rand_i = rand() % num_of_vehicles ;
                if(vehicles[rand_i]->get_exit_segment() == true){
                    pass(rand_i);
                    num_of_exit_vehicles--;
                }
            }
            if(num_of_vehicles!=capacity) {
                int copy_pointer=0;
                for(int i=0; i<num_of_vehicles; i++){
                    if (vehicles[i]!=NULL){
                        if (i!=copy_pointer){
                            vehicles[copy_pointer]=vehicles[i];
                        }
                        copy_pointer++; 
                    }
                }
            }
            flag=true;
        }
//ENTER
        int enter_toll_vehicles= enter(NSegs);
//PRINTS
        bool flag2=false;
        if(enter_toll_vehicles < seg_entrance->get_num_of_vehicles()) {
            cout << "Delays in entrance of node " << seg_entrance->get_node() << endl;
            flag2=true;
        } 
        if(flag) 
            cout << "Delays after the node " << seg_entrance->get_node()<< endl;
        if(flag==false && flag2==false)
            cout << "Keep a safe distance in the segment after the node " << seg_entrance->get_node() << endl;
    }    
}












    // int num_of_readys = Percent*num_of_vehicles/100;
    // for (int i=0; i<num_of_readys && i<num_of_vehicles; i++){
    //     vehicles[i]->exit_attica();
    //     // vehicles[i]->  get_destination
    // }  

                    // vehicle** help_array;
                // int help=0;
                // help_array = new vehicle*[num_of_vehicles];
                // for(int i=0; i<capacity; i++) {
                //     if(vehicles[i]!=NULL) {
                //         help_array[help] = vehicles[i];
                //         vehicles[i] == NULL;
                //         help++;
                //     }
                // }
                // for(int i=0; i<help; i++)
                //     vehicles[i] = help_array[i];


//ENTERRRRRRRRRRRRRRRR

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



        // while(num_of_vehicles<capacity) {
    //     vehicle* toll_vehicle = seg_entrance.operate(NSegs, K, capacity);
    //     if(toll_vehicle!=NULL) {
    //         vehicles[num_of_vehicles-1] = toll_vehicle;
    //         num_of_vehicles++;
    //         capacity--;
    //     }
    // }


//PASSSSSSSSSSSSSSSSSSSSS

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
    
    
//ENTERRRR
    
    
    
       // if (previous != -1) {
    
        // int previous_segment_capacity = pointer_to_attica->get_segment(previous)->capacity;

        // for(int i=0; i<previous_segment_capacity; i++){
        //     vehicle* current_vehicle =pointer_to_attica->get_segment(previous)->vehicles[i];
        //     if (num_of_vehicles<capacity){
        //         if(current_vehicle!=NULL){
        //             for(int j=0; j<capacity; j++){
        //                 if(vehicles[j] == NULL) {
        //                     vehicles[j] = current_vehicle;
        //                     num_of_vehicles++;
        //                 }
        //             }
        //         }
        //     }
        //     else break;
        // }
    // }

    // int enter_toll_vehicles=num_of_vehicles;
    // seg_entrance->operate(NSegs, Kappa, capacity);
    // if(num_of_vehicles<capacity) {
    //     enter_toll_vehicles = seg_entrance->operate(NSegs, Kappa, capacity);
    //     num_of_vehicles += enter_toll_vehicles;
    // }