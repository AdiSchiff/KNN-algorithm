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
    
    string _k;
    string _distanceMetric;
    vector <StructVec> testVectors;
    vector <StructVec> trainVectors;

    KnnDetails();
    void setK(string k);
    void setDistanceMetric(string distanceMetric);
    void setTrainVectors(StructVec);
    void setTestVectors(StructVec);
    void clearTrainVectors();
    void clearTestVectors();


    vector <StructVec> getTestVectors();
    vector <StructVec> getTrainVectors();
    string getK();
    string getDistanceMetric();

};


#endif
