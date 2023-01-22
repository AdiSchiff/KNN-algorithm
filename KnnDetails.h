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
private:
    string k;
    bool isClassified=false;
    string distanceMetric;
    vector <StructVec> testVectors;
    vector <StructVec> trainVectors;
public:
    KnnDetails();
    void setK(string k);
    void setDistanceMetric(string distanceMetric);
    void setTrainVectors(const StructVec&);
    void setTestVectors(const StructVec&);
    void clearTrainVectors();
    void clearTestVectors();
    void setIsClassified(bool answer);

    vector <StructVec> getTestVectors();
    vector <StructVec> getTrainVectors();
    bool getIsClassified();
    string getK();
    string getDistanceMetric();
    ~KnnDetails();
};


#endif