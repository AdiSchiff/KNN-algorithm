/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "KnnDetails.h"
#include <utility>
#include <vector>

KnnDetails:: KnnDetails(){
    k = "5";
    distanceMetric = "AUC";
}
void KnnDetails:: setK(string _k){
    k=std::move(_k);
}
void KnnDetails:: setDistanceMetric(string _distanceMetric){
    distanceMetric=std::move(_distanceMetric);
}
void KnnDetails:: setTestVectors(const StructVec& vector){ testVectors.push_back(vector);}
void KnnDetails:: setTrainVectors(const StructVec& vector){ trainVectors.push_back(vector);}
void KnnDetails::clearTrainVectors() { trainVectors.clear();}
void KnnDetails::clearTestVectors(){ testVectors.clear();}
bool KnnDetails::getIsClassified() { return isClassified;}

vector <StructVec>* KnnDetails::getTestVectors() {return &testVectors;}
vector <StructVec>* KnnDetails::getTrainVectors(){ return &trainVectors;}
void KnnDetails::setIsClassified(bool answer) {
    isClassified=answer;
}
string KnnDetails:: getK(){return k;}
string KnnDetails:: getDistanceMetric(){return distanceMetric;}