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

    for (int i=0; i<num_of_vehicles; i++) 
        vehicles[i] = new vehicle(random(node, NSegs));            
}
segment::~segment() {
    for (int i=0; i<capacity; i++)
        delete vehicles[i];
    delete vehicles;
    delete seg_entrance;
}

void segment::set_K(int K) {
    Kappa=K;
    pointer_to_attica->set_K(Kappa);
}

void segment::rebuild() {
    for(int i=1; i<num_of_vehicles; i++) {   //bubble sort
        for(int j=num_of_vehicles; j<i-1; j--) {
            if(vehicles[j-1]->is_gone() < vehicles[j]->is_gone()) {
                vehicle temp_veh(vehicles[j-1]->get_exit_node());
                temp_veh.set_ready(vehicles[j-1]->get_ready());
                delete vehicles[j-1];
                vehicles[j-1] = new vehicle(*vehicles[j]);
                delete vehicles[j];
                vehicles[j] = new vehicle(temp_veh);
            }
        }
    }
    int counter=1;
    for(int i=0; i<num_of_vehicles; i++) {
        if(vehicles[i]->is_gone()) 
            break;
        counter++;
    }
    num_of_vehicles = counter;
}

int segment::enter(int NSegs) {
    int enter_vehicles = seg_entrance->operate(NSegs, Kappa);
    pointer_to_attica->set_vehicles(enter_vehicles);
    return enter_vehicles;
}

void segment::exit(){
 cout << "eedo pera" <<num_of_vehicles  << endl;
    bool flag=false;
    for(int i=0; i<num_of_vehicles; i++) {  
        cout << "eedo pera" <<i  << endl;
        if(vehicles[i]->is_gone() == false && vehicles[i]->exit_attica(seg_entrance->get_node())) {
            cout << "eedo pera mphke" <<num_of_vehicles  << endl;
            vehicles[i]->time_to_go();
            pointer_to_attica->set_vehicles(-1);
            flag=true;
        }
        cout << "eedo pera" <<i  << endl;
    }
    cout << "eedo peraaaaaa" <<num_of_vehicles  << endl;
    if(flag) rebuild();
}

bool segment::pass(int Percent){

    bool flag=false;
    if(previous!=-1) {
        int prev_seg_veh=pointer_to_attica->get_segment(previous)->num_of_vehicles;          // number of vehicles of the previous segment
        if(prev_seg_veh!=0) {

            int num_of_pass_segment = Percent*prev_seg_veh/100 ;                            // how many vehicles will be ready to go to the next segment

            for(int i=0; i<num_of_pass_segment; i++) {                                      // we make random vehicles of the previous segment true = ready
                int rand_i = rand() % prev_seg_veh ;
                pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_ready(true);
            }

            while (capacity >= num_of_vehicles && num_of_pass_segment < 0) {                // we pass as many as random ready vehicles fit
                flag=true;
                int rand_i = rand() % prev_seg_veh ;
                if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).is_gone() != true) {
                    if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).get_ready() == true) {   // pass checked
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_ready(false);
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_ready(seg_entrance->get_node()+1);
                        delete vehicles[num_of_vehicles];
                        vehicles[num_of_vehicles] = new vehicle(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i));
                        pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).time_to_go();
                        num_of_vehicles++;
                        num_of_pass_segment--;
                        pointer_to_attica->get_segment(previous)->rebuild();                // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions  
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

    // int counter=1;
    // for(int i=0; i<num_of_vehicles; i++) {
    //     if(vehicles[i]->is_gone()) 
    //         break;
    //     counter++;
    // }
    // num_of_vehicles = counter;

}