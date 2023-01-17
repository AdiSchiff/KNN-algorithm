/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "KnnDetails.h"

void KnnDetails:: setTrainCSV(string trainCSV){
    _trainCSV=trainCSV;
}
void KnnDetails:: setTestCSV(string testCSV){
    _testCSV=testCSV;
}
void KnnDetails:: setK(int k){
    _k=k;
}
void KnnDetails:: setDistanceMetric(string distanceMetric){
    _distanceMetric=distanceMetric;
}

string KnnDetails:: getTrainCSV(){
    return _trainCSV;
}
string KnnDetails:: getTestCSV(){
    return _testCSV;
}
int KnnDetails:: getK(){
    return _k;
}
string KnnDetails:: getDistanceMetric(){
    return _distanceMetric;
}