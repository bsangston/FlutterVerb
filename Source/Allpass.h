//
//  Allpass.hpp
//  FlutterVerb
//
//  Created by Brandon Sangston on 4/30/17.
//
//

#ifndef Allpass_h
#define Allpass_h

#include <stdio.h>

class Allpass {
public:
    Allpass();
    Allpass(float delay);
    ~Allpass();
    float filter(float in);
    float setDelay(float delay);
    
private:
    float b0, aD;
    float zD;

};

#endif /* Allpass_h */
