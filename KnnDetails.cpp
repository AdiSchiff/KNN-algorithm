/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "KnnDetails.h"
#include <vector>
KnnDetails:: KnnDetails(){
    _k = "5";
    _distanceMetric = "AUC";
}
void KnnDetails:: setK(string k){
    _k=k;
}
void KnnDetails:: setDistanceMetric(string distanceMetric){
    _distanceMetric=distanceMetric;
}
void KnnDetails:: setTestVectors(StructVec vector){ testVectors.push_back(vector);}
void KnnDetails:: setTrainVectors(StructVec vector){ trainVectors.push_back(vector);}
void clearTrainVectors(){ trainVectors.clear();}
void clearTestVectors(){ testVectors.clear();}


vector <StructVec> getTestVectors() {return testVectors;}
vector <StructVec> getTrainVectors(){ return trainVectors;}

string KnnDetails:: getK(){return _k;}
string KnnDetails:: getDistanceMetric(){return _distanceMetric;}