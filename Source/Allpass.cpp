//
//  Allpass.cpp
//  FlutterVerb
//
//  Created by Brandon Sangston on 4/30/17.
//
//

#include "Allpass.h"

Allpass::Allpass() {
    zD = 187; //arbitrary default delay value
}

Allpass::Allpass(float delay) {
    zD = delay;
}


Allpass::~Allpass(){
    
}

