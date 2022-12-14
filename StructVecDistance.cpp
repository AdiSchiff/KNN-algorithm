/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "Distance.cpp"
#include "StructVecDistance.h"
using namespace std;


/******************

Function Name:calcDis
Input: vector<structVec> vecS = vector that contains the KNN values as structs
        vector<double> v = the input vector from the user
        string dis = the name of the distance function we need to use.
Output: no output
Function Operation: calculate the distance between the input vector and each of the KNN vectors,
                    using the distance function given as an argument.
******************/
void calcDis(vector<structVec> vecS, vector<double> v, string dis){
    for(vec:vecS){
        switch (dis)
        {
        case AUC:
            vec.setDis(euclideanDistance(vec,v));
            break;
        case MAN:
            vec.setDis(manhattanDistance(vec,v));
            break;
        case CHB:
            vec.setDis(chebyshevDistance(vec,v));
            break;
        case CAN:
            vec.setDis(canberraDistance(vec,v));
            break;
        case MIN:
            vec.setDis(minkowskiDistance(vec,v,2));
            break;
        default:
            break;
        }
    }
}