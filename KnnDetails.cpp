/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "KnnDetails.h"

/******************
* Function Name: KnnDetails
* Input: no input
* Output: no output
* Function Operation: constructor.
* ******************/
KnnDetails:: KnnDetails(){
    k = "5";
    distanceMetric = "AUC";
}

/******************
* Function Name: setK
* Input: string k
* Output: no output
* Function Operation: set k to be a given value.
* ******************/
void KnnDetails:: setK(string _k){
    k=std::move(_k);
}

/******************
* Function Name: setDistanceMetric
* Input: string distance
* Output: no output
* Function Operation: set distance to be a given value.
* ******************/
void KnnDetails:: setDistanceMetric(string _distanceMetric){
    distanceMetric=std::move(_distanceMetric);
}

/******************
* Function Name: setTestVectors
* Input: StructVec& vector
* Output: no output
* Function Operation: adding a given structVector into testVectors.
* ******************/
void KnnDetails:: setTestVectors(const StructVec& vector){ testVectors.push_back(vector);}

/******************
* Function Name: setTrainVectors
* Input: StructVec& vector
* Output: no output
* Function Operation: adding a given structVector into trainVectors.
* ******************/
void KnnDetails:: setTrainVectors(const StructVec& vector){ trainVectors.push_back(vector);}

/******************
* Function Name: clearTrainVectors
* Input: no input
* Output: no output
* Function Operation: clear trainVectors.
* ******************/
void KnnDetails::clearTrainVectors() { trainVectors.clear();}

/******************
* Function Name: clearTestVectors
* Input: no input
* Output: no output
* Function Operation: clear testVectors.
* ******************/
void KnnDetails::clearTestVectors(){ testVectors.clear();}

/******************
* Function Name: getIsClassified
* Input: no input
* Output: boolean value
* Function Operation: return true if it's classified.
* ******************/
bool KnnDetails::getIsClassified() const { return isClassified;}

/******************
* Function Name: getTestVectors
* Input: no input
* Output: pointer to a vector of type StructVec
* Function Operation: return a pointer to testVectors.
* ******************/
vector <StructVec>* KnnDetails::getTestVectors() {return &testVectors;}

/******************
* Function Name: getTrainVectors
* Input: no input
* Output: pointer to a vector of type StructVec
* Function Operation: return a pointer to trainVectors.
* ******************/
vector <StructVec>* KnnDetails::getTrainVectors(){ return &trainVectors;}

/******************
* Function Name: setIsClassified
* Input: boolean value
* Output: no output
* Function Operation: set isClassified to be a given value.
* ******************/
void KnnDetails::setIsClassified(bool answer) {
    isClassified=answer;
}

/******************
* Function Name: getK
* Input: no input
* Output: string k
* Function Operation: return k.
* ******************/
string KnnDetails:: getK(){return k;}

/******************
* Function Name: getDistanceMetric
* Input: no input
* Output: string distance metric
* Function Operation: return distanceMetric.
* ******************/
string KnnDetails:: getDistanceMetric(){return distanceMetric;}

/**
 * destructor
 **/
KnnDetails::~KnnDetails() {}
