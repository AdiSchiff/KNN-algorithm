/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#include "VectorArithmetic.h"

/******************

Function Name:addVectors
Input: vector<double> vector1,vector<double> vector2
Output:vector<double>
Function Operation: merge 2 vectors into new one. without changing the original vectors
******************/
vector<double> VectorArithmetic::addVectors(vector<double> vector1, vector<double> vector2) {
    vector<double> addVec;
    //both if the vectors have the same size
    int vectorsSize = vector1.size();
    int i;
    for (i = 0; i < vectorsSize; i++) {
        addVec.push_back(vector1.at(i) + vector2.at(i));
    }
    return addVec;
}

/******************

Function Name:subtractVectors
Input: vector<double> vector1,vector<double> vector2
Output:vector<double>
Function Operation:subtract vectors and merge the result to new vector
******************/
vector<double> VectorArithmetic::subtractVectors(vector<double> vector1, vector<double> vector2) {
    vector<double> subVec;
    //both if the vectors have the same size
    int vectorsSize = vector1.size();
    int i;
    for (i = 0; i < vectorsSize; i++) {
        subVec.push_back(vector1.at(i) - vector2.at(i));
    }
    return subVec;
}

/******************

Function Name:multVector
Input: vector<double> vector
Output:vector<double>
Function Operation:mult vector by power of 2
******************/
vector<double> VectorArithmetic::powVector(vector<double> vector, int power) {
    std::vector<double> powVec;
    //both if the vectors have the same size
    int i;
    for (i = 0; i < vector.size(); i++) {
        powVec.push_back(pow(vector.at(i), power));
    }
    return powVec;
}


/******************

Function Name:sumVector
Input: vector<double> vector
Output:double sum
Function Operation:sum all the values in the vector
******************/
double VectorArithmetic::sumVector(vector<double> vector) {
    double sum = 0;
    int i;
    for (i = 0; i < vector.size(); i++) {
        sum += vector.at(i);
    }
    return sum;
}

/******************

Function Name:absoluteValueVector
Input: vector<double> vector
Output:vector <double>
Function Operation:return the vector with it's absolute values
******************/
vector<double> VectorArithmetic::absoluteValueVector(vector<double> vector) {
    int i;

    for (i = 0; i < vector.size(); i++) {
        vector.at(i) = abs(vector.at(i));
    }
    return vector;
}

/******************

Function Name:maxValueVector
Input: vector<double> vector
Output:double maxValue
Function Operation:return the max
******************/
double VectorArithmetic::maxValueVector(vector<double> vector) {
    //Sets the maximum to be the first value in the vector
    double maxValue = vector.at(0);
    int i;
    for (i = 0; i < vector.size(); i++) {
        if (vector.at(i) > maxValue) {
            maxValue = vector.at(i);
        }
    }
    return maxValue;
}

/******************

Function Name:divisionVectors
Input: vector<double> vector
Output: vector<double> divided vector
Function Operation:new vector with the divide values from vector1+vector2
******************/

vector<double> VectorArithmetic::divisionVectors(vector<double> vector1, vector<double> vector2) {
    vector<double> divideVec;
    //both if the vectors have the same size
    int vectorsSize = vector1.size();
    int i;
    for (i = 0; i < vectorsSize; i++) {
        divideVec.push_back(vector1.at(i) / vector2.at(i));
    }
    return divideVec;
}