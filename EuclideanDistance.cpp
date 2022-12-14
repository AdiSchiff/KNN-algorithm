/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "EuclideanDistance.h"

/******************
* Function Name: euclideanDistance
* Input: 2 vectors
* Output: print the euclidean distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* according to: d(p,q)={sqrt {(p-q)^{2}}}
* for elaboration: https://en.wikipedia.org/wiki/Euclidean_distance
* ******************/
double EuclideanDistance::distance(vector<double> v1, vector<double> v2) {
    if (v1 == v2) { return 0; }
    ordinaryV = va.subtractVectors(v1, v2);
    ordinaryV = va.powVector(ordinaryV, 2);
    double sum = va.sumVector(ordinaryV);
    return sqrt(sum);
}