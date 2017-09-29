//
//  main.cpp
//  Evol'artist
//
//  Created by Emma Barme on 28/09/2017.
//  Copyright GNU General Public License v3.0
//
//  Last modified by Emma Barme on 29/09/2017


//main function for tests

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "simulEngine/World.hpp"
using namespace std;

int main(){
    
    srand ((unsigned int)time(NULL));
    
    cout << "Hello World!" << endl;
    
    // Run the simulation. No insight on what's happening in the back box for now
    World myWorld(10, 1);
    for (int t = 0; t < 14; t++) {
        myWorld.runSimulationStep();
    }
    
    return 0;
    
}
