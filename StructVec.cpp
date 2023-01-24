/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "StructVec.h"

/******************
* Function Name: StructVec
* Input: vector and a string
* Output: no output
* Function Operation: create a StructVec
* ******************/
StructVec::StructVec(vector<double> vec1, string name1) {
    vec = vec1;
    name = name1;
    distance = 0;
}

/******************
* Function Name: StructVec
* Input: vector 
* Output: no output
* Function Operation: create a StructVec
* ******************/
StructVec::StructVec(vector<double> vec1) {
    vec = vec1;
    name = "";
    distance = 0;
}
/******************
* Function Name: getVector
* Input: no input
* Output: vector
* Function Operation:  return the vector
* ******************/
vector<double> StructVec::getVector() {
    return vec;
}

/******************
* Function Name: setDistance
* Input: new distance value
* Output: no output
* Function Operation: update the distance value
* ******************/
void StructVec::setDistance(double dist) {

    distance = dist;
}

/******************
* Function Name: getName
* Input: no input
* Output: string name
* Function Operation:  return the name
* ******************/
 string StructVec::getName() const {
    return name;
}

/******************
* Function Name: getDistance
* Input: no input
* Output: double distance
* Function Operation:  return the distance
* ******************/
double StructVec::getDistance() const {
    return distance;
}

void StructVec:: setName(string name1){
    this->name=name1;
}