/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef STRUCTVEC_H_
#define STRUCTVEC_H_

#include<vector>
#include<string>
#include "Distance.h"

using namespace std;

class StructVec {
private:
    vector<double> vec;
    string name;
    double distance;
public:
    StructVec(vector<double> vec1, string name1);
    StructVec(vector<double> vec1);
    vector<double> getVector();
    const string &getName() const;
    double getDistance() const;
    void setDistance(double dist);
    void setName(string name1);
};

#endif 
