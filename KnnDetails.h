/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef KNNDETAILS_H_
#define KNNDETAILS_H_

#include "StructVec.h"
class KnnDetails {
    
    int _k;
    string _distanceMetric;
    vector <StructVec> testVectors;
    vector <StructVec> trainVectors;
    
    void setK(int k);
    void setDistanceMetric(string distanceMetric);

    
    int getK();
    string getDistanceMetric();

};


#endif
