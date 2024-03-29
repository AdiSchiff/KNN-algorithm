/*
Ex 1 part 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include <vector>
#include <cmath>
#include "Distance.h"
#include "VectorArithmetic.h"
#include <iostream>
using namespace std;

/******************
* Function Name: euclideanDistance
* Input: 2 vectors
* Output: print the euclidean distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* acording to: d(p,q)={sqrt {(p-q)^{2}}}
* for ellaboration: https://en.wikipedia.org/wiki/Euclidean_distance
* ******************/
double euclideanDistance(vector<double> v1, vector<double> v2) {
    if(v1==v2){return 0;}
    return minkowskiDistance(v1,v2,2);
}

/******************
* Function Name: manhattanDistance
* Input: 2 vectors
* Output: print the manhattan distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* acording to: d(p,q)=|p-q|=sum_{i=1}^{n} |p_{i} - q_{i}|
* for ellaboration: https://en.wikipedia.org/wiki/Taxicab_geometry
* ******************/
double manhattanDistance(vector <double> v1, vector <double> v2) {
        if(v1==v2){return 0;}
    vector <double> v3 = subtractVectors(v1,v2);
    v3 = absoluteValueVector(v3);
    double sum = sumVector(v3);
    return sum;
}

/******************
* Function Name: chebyshevDistance
* Input: 2 vectors
* Output: print the chebyshev distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* acording to: D(x,y):=max(|x_{i} - y_{i}|)
* for ellaboration: https://en.wikipedia.org/wiki/Chebyshev_distance
* ******************/
double chebyshevDistance(vector <double> v1, vector <double> v2) { 
        if(v1==v2){return 0;}

    vector <double> v3 = subtractVectors(v1,v2);
    v3 = absoluteValueVector(v3);
    double maxVal = maxValueVector(v3);
    return maxVal;
}

/******************
* Function Name: canberraDistance
* Input: 2 vectors
* Output: print the canberra distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* acording to: d(p,q)=sum_{i=1}^{n} {{|p_{i}-q_{i}|} / {|p_{i}|+|q_{i}|}}
* for ellaboration: https://en.wikipedia.org/wiki/Canberra_distance
* ******************/
double canberraDistance(vector <double> v1, vector <double> v2) {
        if(v1==v2){return 0;}

    vector <double> v1Abs = absoluteValueVector(v1);
    vector <double> v2Abs = absoluteValueVector(v2);
    vector <double> vAbs = addVectors(v1Abs, v2Abs);
    vector <double> v3 = subtractVectors(v1,v2);
    v3 = absoluteValueVector(v3);
    v3 = divisionVectors(v3,vAbs);
    double sum = sumVector(v3);
    return sum;
}

/******************
* Function Name: minkowskiDistance
* Input: 2 vectors and an int for the pow
* Output: print the minkowski distance between the vectors
* Function Operation:calculating the euclidean distance between two vectors
* acording to: D(X,Y)=(sum_{i=1}^{n} |x_{i} - y_{i}|^{p})^{\1/p}
* for ellaboration: https://en.wikipedia.org/wiki/Minkowski_distance
* ******************/
double minkowskiDistance(vector <double> v1, vector <double> v2, int p) {
        if(v1==v2){return 0;}

    vector <double> v3 = subtractVectors(v1,v2);
    v3 = powVector(v3,p);
    double sum = sumVector(v3);
    return sqrt(sum);
}
