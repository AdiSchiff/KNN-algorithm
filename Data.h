/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef DATA_H_
#define DATA_H_

#include <string>
#include<vector>
#include <map>
#include <iterator>
#include <fstream>
#include <iostream>
#include "Distance.h"
#include "StructVec.h"
#include "ReceiveVector.h"

using namespace std;

class Data {
private:
    map<string, int> kDistances;
    vector<StructVec> structVec;
public:
    StructVec *createStructVector(string line);

    vector<StructVec> *initializeStructVec(string filePath);

    void calcDis(Distance *dis, const vector<double> &vec);

    void sortDistances(int k);

    string findName(int k);
};


#endif 
