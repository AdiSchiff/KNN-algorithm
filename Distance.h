/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef DISTANCE_H_
#define DISTANCE_H_

#include <vector>
#include <iostream>
#include <cmath>
#include <vector>
#include "VectorArithmetic.h"

using namespace std;

class Distance {
protected:
    vector<double> ordinaryV;
    VectorArithmetic va;
public:
    virtual double distance(vector<double> v1, vector<double> v2);
};

#endif