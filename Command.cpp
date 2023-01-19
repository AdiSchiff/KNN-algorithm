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

StructVec* UploadData::createStructVector(const string& line) {
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
        if (line == "error"){return;}
        if(line == "finish"){break;}
        knnDetails->setTrainVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
    dio->write("Please upload your local test CSV file");
    knnDetails->clearTestVectors();
    //gets lines from train file
    while (true)
    {
        string line= dio->read();
        if(line == "finish"){break;}
        knnDetails->setTestVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
}

UploadData::~UploadData() {}



/*class algoSetting*/
AlgoSettings::AlgoSettings(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "2. algorithm settings";
}

bool AlgoSettings::isValidK(const string& k){
    if(stoi(k) < 0 || stoi(k) > (knnDetails->getTestVectors()).size() ){ return false;}
    return true;
}

bool AlgoSettings::isValidDistance(const string& distance){
    if(distance == "AUC" || distance == "MAN" || distance == "CHB" || distance == "CAN" || distance == "MIN"){
        return true;
    }
    return false;
}

void AlgoSettings::execute() {
    string parameters = "The current KNN parameters are: K = " + knnDetails->getK() + ", distance metric = " + knnDetails->getDistanceMetric();
    string message = dio->read();
    if( message == "\n"){
        dio->write("finish");
        return;
    }
    string word, output;
    stringstream ss(message);
    getline(ss, word, ' ');
    if(isValidDistance(word)){
        knnDetails->setK(word);
    } else {
        output = "invalid value for metric\n";
    }
    getline(ss, word, ' ');
    if(isValidK(word)){
        knnDetails->setDistanceMetric(word);
    } else {
        output+= "invalid value for K";
    }
    if(isValidDistance(knnDetails->getDistanceMetric()) && isValidK(knnDetails->getK())){
        output = "finish";
    }
    dio->write(output);
}

AlgoSettings::~AlgoSettings() {}



/*class classify*/
Classify::Classify(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "3. classify data";
}

void Classify::execute() {

}

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