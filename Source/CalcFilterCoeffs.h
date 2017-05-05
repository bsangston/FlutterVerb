//
//  CalcFilterCoeffs.hpp
//  FlutterVerb
//
//  Created by Brandon Sangston on 4/30/17.
//
//

#ifndef CalcFilterCoeffs_h
#define CalcFilterCoeffs_h

#include <stdio.h>
#include <math.h>

class CalcFilterCoeffs {
public:
    static void calcCoeffsLPF(float* coeffs, float fc, float Q, float fs);
    
    static void calcCoeffsHPF(float* coeffs, float fc, float Q, float fs);
    
    static void calcCoeffsBPF(float* coeffs, float fc, float fs);
    
    static void calcCoeffsNotch(float* coeffs, float fc, float gainDB, float Q, float fs);
    
    static void calcCoeffsAPF(float* coeffs, float fc, float fs);
    
    static void calcCoeffsComb(float* coeffs, float fc, float fs);

};

#endif /* CalcFilterCoeffs_hp */
