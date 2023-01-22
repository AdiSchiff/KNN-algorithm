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
    if(isValidK(word)){
        knnDetails->setDistanceMetric(word);
    } else {
        output+= "invalid value for K";
    }
    getline(ss, word, ' ');
    if(isValidDistance(word)){
        knnDetails->setK(word);
    } else {
        output = "invalid value for metric\n";
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

Classify ::Distance *whatDis(const char *dis) {
    if (strcmp(dis, "AUC") == 0) {
        auto *ed = new EuclideanDistance();
        return ed;
    }
    if (strcmp(dis, "MAN") == 0) {
        auto *mad = new ManhattanDistance();
        return mad;
    }
    if (strcmp(dis, "CHB") == 0) {
        auto *chd = new ChebyshevDistance();
        return chd;
    }
    if (strcmp(dis, "CAN") == 0) {
        auto *cad = new CanberraDistance();
        return cad;
    }
    if (strcmp(dis, "MIN") == 0) {
        auto *mid = new Minkowski();
        return mid;
    }
    else {
        return NULL;
    }
}

void Classify::calcDis(Distance *dis, const vector<double> &vec) {
    for (auto &&v: knnDetails->getTrainVectors()) {
        v.setDistance(dis->distance(vec, v.getVector()));
    }
}
void Classify::sortDistances(int k,vector <structVec> *&classified) {
    for (size_t i = 0; i < k; i++) {
        for (size_t j = i; j < classified.size() - 1; j++) {
            if (classified.at(i).getDistance() > classified.at(j + 1).getDistance()) {
                classified temp = classified.at(i);
                classified.at(i) = classified.at(j + 1);
                classified.at(j + 1) = temp;
            }
        }
    }
}

string Classify::findName(int k,vector <structVec> *&classified) {
    string name;
    map<string, int> kDistances;
    //add all the distances to the map
    for (size_t i = 0; i < k; i++) {
        name = classified.at(i).getName();
        if (kDistances.empty()) { kDistances[name] = 1; }
        auto it = kDistances.find(name);
        if (it != kDistances.end()) {
            it->second = it->second + 1;
        } else { kDistances[name] = 1; }
    }

    //find the max
    string maxName="";
    int maxRepetitions = 0;
    map<string, int>::iterator itr;
    for (itr = kDistances.begin(); itr != kDistances.end(); ++itr) {
        if (itr->second > maxRepetitions) {
            maxRepetitions = itr->second;
            maxName = itr->first;
        }
    }
    kDistances.clear();
    return maxName;
}

void Classify::execute() {

    if((knnDetails->getTestVectors()).empty() || (knnDetails->getTrainVectors()).empty()){
        dio->write("please upload data");
        return;
    }
    char *distance = new char[(knnDetails->getDistanceMetric()).length() + 1];
    strcpy(distance, (knnDetails->getDistanceMetric()).c_str());
    auto *dis = whatDis(distance);

    ///////need to check
    for(auto &&v: knnDetails->getTestVectors() ){
        calcDis(dis,v.getVector());
        sortDistances(knnDetails->getK(), knnDetails->getTrainVectors());
        v.setName(findName(knnDetails->getK(), knnDetails->getTrainVectors()));
    }
    dio->write( "complete data classifying ");
    knnDetails->setIsClassified(true);
    return;

}

Classify::~Classify() {}


/*class display*/

Display::Display(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "4. display results";
}

void Display::execute() {
    if((knnDetails->getTestVectors()).empty() || (knnDetails->getTrainVectors()).empty()){
        dio->write("please upload data");
        return;
    }
    if(!knnDetails->getIsClassified()){
        dio->write( "data the classify please");
        return;
    }

    int counter = 1;
    string counterString;
    strint output;
    for (auto &&v: knnDetails->getTestVectors()) {
        counterString = to_string(counter);
        output= counterString+"\t"+v.getName();
        dio->write(output);
        counter++;
    }
    dio->write("Done");
}
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