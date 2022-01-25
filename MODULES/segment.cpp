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
        if(vehicles[i]!=NULL && vehicles[i]->exit_attica()) {
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
                // cout << "gggggg2" << endl;
                // cout << num_of_vehicles << "i  " << i << endl;
    }
    num_of_vehicles -= counter;
    for(int i=0; i<num_of_vehicles; i++) {
        cout << "ee seg " << endl;
        cout << vehicles[i]->get_exit_segment() << endl;
    }
    cout << "ee seg sig " << endl;
}

void segment::pass(int i){
    int next_segment_num_of_vehicles = pointer_to_attica->get_segment(next)->num_of_vehicles;
    vehicles[i]->set_exit_segment(false);
    pointer_to_attica->get_segment(next)->set_vehicle(next_segment_num_of_vehicles-1, *vehicles[i]);
    pointer_to_attica->get_segment(next)->set_num_of_vehicles(next_segment_num_of_vehicles+1);
    vehicles[i]=NULL;
    num_of_vehicles--;
}

void segment::operate(int NSegs, int K, int Percent){
//EXIT
        // int copy_pointer=0;
        // for(int i=0; i<num_of_vehicles; i++){
        //     cout << "ggggg3" << endl; 
        //     if(vehicles[i]!=NULL)
        //         if(num_of_vehicles==1 || i!=copy_pointer) {
        //         vehicles[copy_pointer]=vehicles[i];
        //         vehicles[i] = NULL;
        //     }
        //     copy_pointer++;
        // } 
         cout << "ola ok" << endl;
    exit();
    cout << "ggggg1" << endl;

//PASS 
    bool flag=false;
    if(next!=-1 && num_of_vehicles!=0) {   
        int num_of_pass_segment = Percent*num_of_vehicles/100 ;
        int counter=0;
        
        while (counter!=num_of_pass_segment) {
            int rand_i = rand() % num_of_vehicles ;
             cout << "RAND I " <<  rand_i << "  NUMMM"  << num_of_vehicles << endl;
            if(vehicles[rand_i]->get_exit_segment() == false){
                vehicles[rand_i]->set_exit_segment(true);
                counter++;
                cout << "RAND I !!! " <<  rand_i << "  NUMMM"  << num_of_vehicles << endl;
            }
        }
         cout << "ggggg5" << endl;
        num_of_pass_segment=0;
        for(int i=0; i<num_of_vehicles; i++) 
            if(vehicles[i]->get_exit_segment()==true)
                num_of_pass_segment++;

        if(pointer_to_attica->get_segment(next)->capacity >= num_of_pass_segment) {
            for(int i=0; i<num_of_vehicles; i++)
                if(vehicles[i]->get_exit_segment()==true)
                    pass(i);   
            int copy_pointer=0;
                        for(int i=0; i<num_of_vehicles; i++){
                            cout << "ggggg3" << endl; 
                            if(vehicles[i]!=NULL)
                                if(num_of_vehicles==1 || i!=copy_pointer) {
                                vehicles[copy_pointer]=vehicles[i];
                                vehicles[i] = NULL;
                            }
                            copy_pointer++;
                        }  
        }
        else {
            flag=true;
            int num_of_exit_vehicles = num_of_pass_segment - (pointer_to_attica->get_segment(next)->capacity - pointer_to_attica->get_segment(next)->num_of_vehicles);
                cout << "mhpos atrnitikos     " << pointer_to_attica->get_segment(next)->capacity - pointer_to_attica->get_segment(next)->num_of_vehicles << endl;
             cout << "posa num     " << num_of_vehicles << " exit  " << num_of_exit_vehicles << endl;
            while (num_of_exit_vehicles>0 && num_of_vehicles>0) {
                int rand_i = rand() % num_of_vehicles ;
               // cout << "num" << num_of_vehicles << "randd  "<< rand_i << endl;  
                //cout << "gia miso      " << vehicles[rand_i]->get_exit_segment() << endl;
                if(vehicles[rand_i]!=NULL){
                    if(vehicles[rand_i]->get_exit_segment() == true) {
                        cout << "ggggg2.5" << endl;
                        pass(rand_i);
                        cout <<"veh  " << num_of_vehicles << "  exit " << num_of_exit_vehicles << endl; 
                        num_of_exit_vehicles--;
                        int copy_pointer=0;
                        for(int i=0; i<num_of_vehicles; i++){
                            cout << "ggggg3" << endl; 
                            if(vehicles[i]!=NULL)
                                if(num_of_vehicles==1 || i!=copy_pointer) {
                                vehicles[copy_pointer]=vehicles[i];
                                vehicles[i] = NULL;
                            }
                            copy_pointer++;
                        }  
                    }
                }
            }
        }
    }       // for(int i=0; i<num_of_vehicles; i++){
                //         cout << "ggggg4" << endl;
                //         if(vehicles[i]!=NULL){
                //             if(i!=copy_pointer) {
                //                 vehicles[copy_pointer]=vehicles[i];
                //                 vehicles[i] = NULL;
                //             }
                                
                //             copy_pointer++; 
                //         } 
               // cout << "ggggg3" << endl;  
                //if(num_of_vehicles!=0) {
                 //   cout << "ggggg3.5" << endl;
                //     int copy_pointer=0;
                //     for(int i=0; i<num_of_vehicles; i++){
                //         cout << "ggggg4" << endl;
                //         if(vehicles[i]!=NULL){
                //             if(i!=copy_pointer) {
                //                 vehicles[copy_pointer]=vehicles[i];
                //                 vehicles[i] = NULL;
                //             }
                                
                //             copy_pointer++; 
                //         } 
                //     }
                // //}
                   
                  
            
            //  cout << "ggggg3" << endl;  
            // if(num_of_vehicles!=0) {
            //      cout << "ggggg3.5" << endl;
            //     int copy_pointer=0;
            //     for(int i=0; i<num_of_vehicles; i++){
            //         cout << "ggggg4" << endl;
            //         if(vehicles[i]!=NULL){
            //             if(i!=copy_pointer)
            //                 vehicles[copy_pointer]=vehicles[i];
            //             copy_pointer++; 
            //         }
                    
            //     }
            // }
      
    
  
//ENTER
   cout << "enter ptobb " << endl;
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