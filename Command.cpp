//
// Created by adi on 1/15/23.
//
#include "Command.h"

/*class command*/
string Command::getDescription() const {
    return this->description;
}
Command::Command(DefaultIO *_dio, KnnDetails *_knn) : dio(_dio), knnDetails(_knn){}

Command::~Command() {}




/*class welcome*/
Welcome::Welcome(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn){
    description = "Welcome to the KNN Classifier Server. please choose an option:";
}

void Welcome::execute() { return; }

Welcome::~Welcome() {}



/*class uploadData*/
UploadData::UploadData(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "1. upload an unclassified csv data file";
}

StructVec *UploadData::createStructVector(string line) {

    string name;
    string tempVec;
    string vecString;
    string temp;
    for (char c: line) {
        if (c == ',') {
            temp += " ";
            tempVec += temp;
            temp = "";
        } else {
            temp += c;
        }
    }
    for (size_t i = 0; i < tempVec.size() - 1; i++) {
        vecString += tempVec[i];
    }
    name.append(temp);
    auto *rv = new ReceiveVector();

    auto *sv = new StructVec(rv->transferStringToVector(vecString), name);
    return sv;
}

void UploadData::execute() {
    dio->write("Please upload your local train CSV file");
    knnDetails->clearTrainVectors();
    //gets lines from train file
    while (true)
    {
        string line= dio->read();
        if (line.compare("error") == 0){return;}
        if(line.compare("finish") == 0){break;}
        knnDetails->setTrainVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
    dio->write("Please upload your local test CSV file");
    knnDetails->clearTestVectors();
    //gets lines from train file
    while (true)
    {
        string line= dio->read();
        if(line.compare("finish") == 0){break;}
        knnDetails->setTestVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
    return;
}

UploadData::~UploadData() {}



/*class algoSetting*/
AlgoSettings::AlgoSettings(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "2. algorithm settings";
}

bool AlgoSettings::isValidk(string k){
    if(stoi(k) < 0 || stoi(k) > (knnDetails->getTestVectors()).size() ){ return false;}
    return true;
}

bool AlgoSettings::isValidDistance(string distance){
    if((strcmp(distance, "AUC") == 0) || (strcmp(distance, "MAN") == 0) || (strcmp(distance, "CHB") == 0)){return true;}
    if((strcmp(distance, "CAN") == 0) || (strcmp(distance, "MIN") == 0)){ return true;}
    return false;
}
void AlgoSettings::execute() {
    string parameters = "The current KNN parameters are: K = " + knnDetails->getK + ", distance metric = " + knnDetails->getDistanceMetric;
    message = dio->read();
    if( message == "\n"){
        dio->write("finish");
        return;
    }
    string word;
    stringstream ss(message);
    getline(ss, word, ' ');
    knnDetails->setK(word);
    getline(ss, word, ' ');
    knnDetails->setDistanceMetric(word);
    if(isValidDistance() && isValidk()){
        dio->write("finish");
        return;
    }
    string output="";
    if(!isValidDistance()){ output = "invalid value for metric\n";}
    if(!isValidk()){ output+= "invalid value for K";}
    dio->write(output);
    return;



}

AlgoSettings::~AlgoSettings() {}





/*class classify*/
Classify::Classify(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "3. classify data";
}

void Classify::execute() {}

Classify::~Classify() {}

Display::Display(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "4. display results";
}

void Display::execute() {}

Display::~Display() {}

Download::Download(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "5. download results";
}

void Download::execute() {}

Download::~Download() {}

Exit::Exit(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "8. exit";
}

void Exit::execute() {}

Exit::~Exit() {}
