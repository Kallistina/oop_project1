#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../INCLUDES/segment.h"

using namespace std;
int random (int low, int high);

segment::segment(int NSegs, int K, int previous_seg, int next_seg, attica* pointer, int node) 
    :  previous(previous_seg), next(next_seg), pointer_to_attica(pointer), num_of_vehicles(0), Kappa(K) {

    seg_entrance = new entrance(NSegs, K, this, node);

    cout << "Give capacity for segment " << seg_entrance->get_node() << endl;
    cin >> capacity ;

    num_of_vehicles = rand() % 3 + 1;
    vehicles = new vehicle*[num_of_vehicles];

    for (int i=0; i<num_of_vehicles; i++){
        vehicles[i] = new vehicle(random(node, NSegs));
        vehicles[i]->set_current_segment(node);          
    }
}

void segment::set_K(int K) {
    Kappa=K;
    pointer_to_attica->set_K(Kappa);
}

int segment::enter(int NSegs) {
    return seg_entrance->operate(NSegs, Kappa);
}

void segment::exit(){
    int copy_pointer=0;
    int counter=0;
    for(int i=0; i<num_of_vehicles; i++){
        if(vehicles[i]->exit_attica()) {
            counter++;
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
    num_of_vehicles -= counter;
}

void segment::pass(int i){
    int next_segment_num_of_vehicles = pointer_to_attica->get_segment(next)->num_of_vehicles;
    vehicles[i]->set_exit_segment(false);
    //pointer_to_attica->get_segment(next)->vehicles[next_segment_num_of_vehicles-1] = vehicles[i];
    //pointer_to_attica->get_segment(next)->get_vehicle(next_segment_num_of_vehicles-1) = *vehicles[i];
    pointer_to_attica->get_segment(next)->set_vehicle(next_segment_num_of_vehicles-1, *vehicles[i]);
    pointer_to_attica->get_segment(next)->set_num_of_vehicles(next_segment_num_of_vehicles+1);
    vehicles[i]=NULL;
    num_of_vehicles--;
}

void segment::operate(int NSegs, int K, int Percent){
//EXIT
    exit();

//PASS 
    bool flag=false;
    if(next!=-1 && num_of_vehicles!=0) {   
        int num_of_pass_segment = Percent*num_of_vehicles/100;
        int counter=0;
        while (counter!=num_of_pass_segment) {
            int rand_i = rand() % num_of_vehicles ;
            if(vehicles[rand_i]->get_exit_segment() == false){
                vehicles[rand_i]->set_exit_segment(true);
                counter++;
            }
        }

        num_of_pass_segment=0;
        for(int i=0; i<num_of_vehicles; i++) 
            if(vehicles[i]->get_exit_segment()==true)
                num_of_pass_segment++;

        if(pointer_to_attica->get_segment(next)->capacity >= num_of_pass_segment) {
            for(int i=0; i<num_of_vehicles; i++)
                if(vehicles[i]->get_exit_segment()==true)
                    pass(i);   
        }
        else {
            flag=true;
            int num_of_exit_vehicles = num_of_pass_segment - pointer_to_attica->get_segment(next)->capacity;
            while (num_of_exit_vehicles>0) {
                int rand_i = rand() % num_of_vehicles ;
                if(vehicles[rand_i]->get_exit_segment() == true)
                    pass(rand_i);
            }
            
            if(num_of_vehicles!=capacity) {
                int copy_pointer=0;
                for(int i=0; i<num_of_vehicles; i++){
                    if(vehicles[i]!=NULL){
                        if(i!=copy_pointer){
                            vehicles[copy_pointer]=vehicles[i];
                        }
                        copy_pointer++; 
                    }
                }
            }
        }
        
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