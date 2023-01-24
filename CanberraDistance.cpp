/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "CanberraDistance.h"

/******************
* Function Name: canberraDistance
* Input: 2 vectors
* Output: print the canberra distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* according to: d(p,q)=sum_{i=1}^{n} {{|p_{i}-q_{i}|} / {|p_{i}|+|q_{i}|}}
* for elaboration: https://en.wikipedia.org/wiki/Canberra_distance
* ******************/

double CanberraDistance::distance(vector<double> v1, vector<double> v2) {
    if (v1 == v2) { return 0; }
    if(v1.size() != v2.size()){ 
        return NULL;
    }
    vector<double> v1Abs = va.absoluteValueVector(v1);
    vector<double> v2Abs = va.absoluteValueVector(v2);
    vector<double> vAbs = va.addVectors(v1Abs, v2Abs);
    ordinaryV = va.subtractVectors(v1, v2);
    ordinaryV = va.absoluteValueVector(ordinaryV);
    ordinaryV = va.divisionVectors(ordinaryV, vAbs);
    double sum = va.sumVector(ordinaryV);
    return sum;
}