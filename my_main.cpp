#include <iostream>
#include <cstdlib>
#include <ctime>
#include "INCLUDES/attica.h"

using std::string;
using namespace std;

int main(int argc, char* argv[]) {

    srand(time(NULL));

    int  N, NSegs, K, Percent;
    N = atoi(argv[1]);
	NSegs = atoi(argv[2]);
	K = atoi(argv[3]);
    Percent = atoi(argv[4]);

    attica my_attica(NSegs, K);

    for(int i=0; i<N; i++)
        my_attica.operate(NSegs, Percent);

}