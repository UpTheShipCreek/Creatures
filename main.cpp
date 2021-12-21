#include <iostream>
#include <time.h>
#include "creatures.h"

using namespace std;
#define HEADS 0


int main(int argc, char *argv[]){
    int i, N, M, L, random_spot, heads_or_tails;
    extern int* good_thrsh;
    extern int* bad_thrsh;

    srand(clock()); 
    good_thrsh = (int*)malloc(sizeof(int)); 
    bad_thrsh = (int*)malloc(sizeof(int)); 

/*--------------------------Getting Arguments--------------------------*/
    if(argc < 6){ 
        cout << "Not enough arguments passed" << endl;
        return -1;
    }
    if(argc > 6){
         cout << "Too many arguments passed" << endl;
        return -1;
    }
    else{
        N = atoi(argv[1]);  //number of creatures for our society
        M = atoi(argv[2]);  //number of actions
        L = atoi(argv[3]);  //Life of a creature
        (*good_thrsh) = atoi(argv[4]);  //life thresholds
        (*bad_thrsh) = atoi(argv[5]);   //life thresholds
    }
/*--------------------------Getting Arguments--------------------------*/

    creature_Society society(N, L);

    for(i = 1; i <= M; i++){
        heads_or_tails = (rand()%2);
        random_spot = (rand()%N) + 1;
        if(heads_or_tails == HEADS){
            society.beat(random_spot);
        }
        else{
            society.bless(random_spot);
        }
    }
    if(society.no_of_good() == N){
        cout << "Good Dominates in the World!" << endl;
    }
    else if(society.no_of_zombies() == N){
        cout << "This is a dead society " << society.no_of_zombies() << endl;
    }
    else {
        cout << "Try again to improve the world" << endl;
    }

    free(good_thrsh);
    free(bad_thrsh);
}