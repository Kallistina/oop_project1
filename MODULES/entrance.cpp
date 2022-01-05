#include <iostream>
#include "../INCLUDES/entrance.h"
#include "../INCLUDES/toll.h"

using std::string;
using namespace std;

// entrance::entrance(){
    

// }

void entrance::operate(int NSegs, int K){
//sub
    for(int i=0; i<5; i++){
        for(int j=0; j<K; j++){
            employe_tolls[i].sub();
        }
         for(int j=0; j<2*K; j++){
            electronic_tolls[i].sub();
        }
    }

    srand(time(NULL));
//add
    for(int i=0; i<5; i++){
        for(int j=0; j<rand() % 20; j++){
            vehicle v(rand() % NSegs);
            employe_tolls[i].add(&v);
        }
        for(int j=0; j<rand() % 20; j++){
            vehicle v(rand() % NSegs);
            electronic_tolls[i].add(&v);
        }
    }
}