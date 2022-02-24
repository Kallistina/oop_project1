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
    if(num_of_vehicles > capacity) num_of_vehicles = capacity;
    vehicles = new vehicle*[capacity];

    for (int i=0; i<num_of_vehicles; i++) {
        vehicles[i] = new vehicle(random(node, NSegs));
        vehicles[i]->set_current_segment(node);          
    }
}

void segment::set_K(int K) {
    Kappa=K;
    pointer_to_attica->set_K(Kappa);
}

int segment::enter(int NSegs) {
    int enter_vehicles = seg_entrance->operate(NSegs, Kappa);
    pointer_to_attica->set_vehicles(enter_vehicles);
    return enter_vehicles;
}

void segment::exit(){
    int copy_pointer=0;
    int counter=num_of_vehicles;
    cout << "enummmmmm " << num_of_vehicles  << endl;

    for(int i=0; i<counter; i++){
        if( vehicles[i]->exit_attica()) {      //vehicles[i]!=NULL &&
            num_of_vehicles--;
            pointer_to_attica->set_vehicles(-1);
            vehicles[i]->set_exit_segment(-10);
            // vehicles[i]=NULL;
            // cout << "gggggg2" << endl;
        }
        else{       
            if (i!=copy_pointer){
                vehicles[copy_pointer]= vehicles[i];
                vehicles[i]->set_exit_segment(-10);
            }
            copy_pointer++; 
        }
    }

    for(int i=0; i<num_of_vehicles; i++) {
        //cout << "ee seg " << endl;
       // cout << num_of_vehicles << endl;
       // cout << vehicles[i]->get_exit_segment() << endl;
    }
    //cout << "ee seg sig " <<num_of_vehicles  << endl;
}

bool segment::pass(int Percent){

    bool flag=false;
    
    int prev_seg_veh=pointer_to_attica->get_segment(previous)->num_of_vehicles;            // number of vehicles of the previous segment
    if(previous!=-1 && prev_seg_veh!=0) {
        int num_of_pass_segment = Percent*prev_seg_veh/100 ;                               // how many vehicles will be ready to go to the next segment
        int counter=0;
        
        while (counter!=num_of_pass_segment) {
            int rand_i = rand() % prev_seg_veh ;                                           // we make random vehicles of the previous segment true = ready
            if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).get_exit_segment()== false) {
                pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_exit_segment(true);
                counter++;
            }
        }

        num_of_pass_segment=0;
        for(int i=0; i<prev_seg_veh; i++)                                                   // how many vehocles are ready
            if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment()==true)
                num_of_pass_segment++;

        if(capacity >= num_of_pass_segment) {   // can we fit them all?
            for(int i=0; i<prev_seg_veh; i++)                                               // pass the vehicles to the segment
                if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment()==true) {
                    pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(false);
                    pointer_to_attica->get_segment(previous)->get_vehicle(i).set_current_segment(seg_entrance->get_node()+1);
                    pointer_to_attica->get_segment(previous)->set_num_of_vehicles(pointer_to_attica->get_segment(previous)->get_num_of_vehicles()-1);
                    *vehicles[num_of_vehicles] = pointer_to_attica->get_segment(previous)->get_vehicle(i);
                    pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(-10);
                    num_of_vehicles++;
                }   
                
            int copy_pointer=0;     // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions
            for(int i=0; i<prev_seg_veh; i++) {
                if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment() != -10) {
                    if(prev_seg_veh==1 || i!=copy_pointer) {
                        pointer_to_attica->get_segment(previous)->get_vehicle(copy_pointer) = pointer_to_attica->get_segment(previous)->get_vehicle(i);
                        pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(-10);
                    }
                    copy_pointer++;
                }
            }  
        }
        else {  // if they don't fit all
            flag=true;
            int num_of_exit_vehicles = num_of_pass_segment - (capacity - pointer_to_attica->get_segment(previous)->num_of_vehicles);

            while (num_of_exit_vehicles>0 && prev_seg_veh>0) {
                int rand_i = rand() % prev_seg_veh ;
                // we pass as many as random ready vehicles fit
                if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).get_exit_segment() != -10) {
                    if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).get_exit_segment() == true) {
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_exit_segment(false);
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_current_segment(seg_entrance->get_node()+1);
                        pointer_to_attica->get_segment(previous)->set_num_of_vehicles(pointer_to_attica->get_segment(previous)->get_num_of_vehicles()-1);
                        *vehicles[num_of_vehicles] = pointer_to_attica->get_segment(previous)->get_vehicle(rand_i);
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_exit_segment(-10);
                        num_of_vehicles++;

                        num_of_exit_vehicles--;
                        int copy_pointer=0;  // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions
                        for(int i=0; i<prev_seg_veh; i++){
                                 
                            if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment() != -10) {
                                if(num_of_vehicles==1 || i!=copy_pointer) {
                                    pointer_to_attica->get_segment(previous)->get_vehicle(copy_pointer) = pointer_to_attica->get_segment(previous)->get_vehicle(i);
                                    pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(-10);
                            
                                }
                                copy_pointer++;
                            }  
                        }  
                    }
                }
            }
        }
    }

    return flag;
}

void segment::operate(int NSegs, int K, int Percent){
//EXIT
    exit();
     cout << "ee seg sig eet" <<num_of_vehicles  << endl;

//PASS 
    bool flag = pass(Percent);
     cout << "ee seg sig pass" <<num_of_vehicles  << endl;

//ENTER
    int enter_toll_vehicles= enter(NSegs);  
     cout << "ee seg sig entr" <<num_of_vehicles  << endl;

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