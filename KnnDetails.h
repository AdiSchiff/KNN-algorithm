/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef KNNDETAILS_H_
#define KNNDETAILS_H_


class KnnDetails {
    string _trainCSV;
    string _testCSV;
    int _k;
    string _distanceMetric;

    void setTrainCSV(string trainCSV);
    void setTestCSV(string testCSV);
    void setK(int k);
    void setDistanceMetric(string distanceMetric);

    string getTrainCSV();
    string getTestCSV();
    int getK();
    string getDistanceMetric();

};


#endif
