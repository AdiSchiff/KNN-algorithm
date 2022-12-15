/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "ManhattanDistance.h"

/******************
* Function Name: manhattanDistance
* Input: 2 vectors
* Output: print the manhattan distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* according to: d(p,q)=|p-q|=sum_{i=1}^{n} |p_{i} - q_{i}|
* for elaboration: https://en.wikipedia.org/wiki/Taxicab_geometry
* ******************/
double ManhattanDistance::distance(vector<double> v1, vector<double> v2) {
    if (v1 == v2) { return 0; }
    if(v1.size() != v2.size()){ 
        cout<< "Error! The vectors are not in the same size"<< endl;
        exit(0);
    }
    ordinaryV = va.subtractVectors(v1, v2);
    ordinaryV = va.absoluteValueVector(ordinaryV);
    double sum = va.sumVector(ordinaryV);
    return sum;
}