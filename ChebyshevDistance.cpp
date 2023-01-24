/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "ChebyshevDistance.h"

/******************
* Function Name: chebyshevDistance
* Input: 2 vectors
* Output: print the chebyshev distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* according to: D(x,y):=max(|x_{i} - y_{i}|)
* for elaboration: https://en.wikipedia.org/wiki/Chebyshev_distance
* ******************/
double ChebyshevDistance::distance(vector<double> v1, vector<double> v2) {
    if (v1 == v2) { return 0; }
    if(v1.size() != v2.size()){ 
        return NULL;
    }
    ordinaryV = va.subtractVectors(v1, v2);
    ordinaryV = va.absoluteValueVector(ordinaryV);
    double maxVal = va.maxValueVector(ordinaryV);
    return maxVal;
}