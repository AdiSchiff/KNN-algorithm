/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#include "Command.h"

/*class command*/

/******************
* Function Name: getDescription
* Input: no input
* Output: the command's description
* Function Operation: return the command's description.
* ******************/
string Command::getDescription() const {
    return this->description;
}

/******************
* Function Name: Command
* Input: the defaultIO and the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Command::Command(DefaultIO *_dio, KnnDetails *_knn) : dio(_dio), knnDetails(_knn){}

/**
 * destructor.
 **/
Command::~Command() {}



/*class welcome*/

/******************
* Function Name: Welcome
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Welcome::Welcome(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn){
    description = "Welcome to the KNN Classifier Server. please choose an option:";
}

/**
 * default implementation for execute of the command class
 **/
void Welcome::execute() { }

/**
 * destructor.
 **/
Welcome::~Welcome() {}



/*class uploadData*/

/******************
* Function Name: UploadData
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
UploadData::UploadData(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "1. upload an unclassified csv data file";
}

/******************
* Function Name: createStructVector
* Input: string line
* Output: pointer to StructVec
* Function Operation:create an object of type StructVec and return a pointer of it.
* ******************/
StructVec* UploadData::createStructVector(const string& line) {
    string name, tempVec, vecString, temp;
    //loop that split the line into 2 strings, one-the vector and two-the classification.
    for (char c: line) {
        if (c == ',') {
            temp += " ";
            tempVec += temp;
            temp = "";
        } else {
            temp += c;
        }
    }
    if(isdigit(temp[0])){
        tempVec += temp;
    }
    for (size_t i = 0; i < tempVec.size() - 1; i++) {
        vecString += tempVec[i];
    }
    name.append(temp);
    auto *rv = new ReceiveVector();
    auto *sv = new StructVec(rv->transferStringToVector(vecString), name);
    return sv;
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: receive string lines and turns them into a structVector objects that contains all the vectors
*   and their classifications of 2 file, the first file of a classified vectors and the second of an unclassified vectors.
* ******************/
void UploadData::execute() {
    dio->write("Please upload your local train CSV file");
    knnDetails->clearTrainVectors();
    string line;
    //gets lines from train file
    while (true)
    {
        line= dio->read();
        if (line == "error"){return;}
        if(line == "finish"){break;}
        knnDetails->setTrainVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
    dio->write("Please upload your local test CSV file");
    knnDetails->clearTestVectors();
    //gets lines from test file
    while (true)
    {
        line= dio->read();
        if (line == "error"){return;}
        if(line == "finish"){break;}
        knnDetails->setTestVectors(*createStructVector(line));
    }
    dio->write("Upload complete");
}

/**
 * destructor.
 **/
UploadData::~UploadData() {}



/*class algoSetting*/

/******************
* Function Name: AlgoSettings
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
AlgoSettings::AlgoSettings(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "2. algorithm settings";
}

/******************
* Function Name: isValidK
* Input: string k
* Output: boolean value
* Function Operation: return true if k is valid and false if it's not.
* ******************/
bool AlgoSettings::isValidK(const string& k){
    char* _k = new char[k.length() + 1];
    strcpy(_k,k.c_str());
    if(!isdigit(*_k) || stoi(k) < 0 ||stoi(k) > (knnDetails->getTestVectors())->size() ){ return false;}
    return true;
}

/******************
* Function Name: isValidDistance
* Input: string distance
* Output: boolean value
* Function Operation: return true if distance is valid and false if it's not.
* ******************/
bool AlgoSettings::isValidDistance(const string& distance){
    if(distance == "AUC" || distance == "MAN" || distance == "CHB" || distance == "CAN" || distance == "MIN"){
        return true;
    }
    return false;
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: receive a string of k and a new distance metric, modify those values if they are valid
*   and inform the client if they are not.
* ******************/
void AlgoSettings::execute() {
    dio->write("The current KNN parameters are: K = " + knnDetails->getK() + ", distance metric = " + knnDetails->getDistanceMetric());
    string message = dio->read();
    if( message == "empty"){
        dio->write("finish");
        return;
    }
    string word, k, output;
    stringstream s(message);
    getline(s,k,' ');
    getline(s, word, ' ');
    if(isValidK(k)){
        knnDetails->setK(k);
    } else {
        output = "invalid value for K ";
    }
    if(word.empty()){
        output += "invalid value for metric";
        dio->write(output);
        return;
    }
    if(isValidDistance(word)){
        knnDetails->setDistanceMetric(word);
    } else {
        output += "invalid value for metric";
    }
    if(isValidDistance(knnDetails->getDistanceMetric()) && isValidK(knnDetails->getK())){
        output = "finish";
   }
    dio->write(output);
}

/**
 * destructor.
 **/
AlgoSettings::~AlgoSettings() {}



/*class classify*/

/******************
* Function Name: Classify
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Classify::Classify(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "3. classify data";
}

/******************
Function Name:whatDis
Input: string dis = the name of the distance function we need to use.
Output: no output
Function Operation: return a distance object according to the distance function given as an argument.
******************/
Distance *Classify::whatDis(const char *dis) {
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

/******************
* Function Name: calcDis
* Input: pointer of a Distance object and a vector
* Output: no output
* Function Operation: calculate all the distances between the given vector and all the vectors in structVec trainVectors.
* ******************/
void Classify::calcDis(Distance *dis, const vector<double> &vec) {
    for(size_t i = 0; i<knnDetails->getTrainVectors()->size(); i++){
        knnDetails->getTrainVectors()->at(i).setDistance(dis->distance(vec, knnDetails->getTrainVectors()->at(i).getVector()));
    }
}

/******************
* Function Name: sortDistances
* Input: no input
* Output: no output
* Function Operation:sort the first k structVec by their distance value.
* ******************/
void Classify::sortDistances() {
    for (size_t i = 0; i < stoi(knnDetails->getK()); i++) {
        for (size_t j = i; j < knnDetails->getTrainVectors()->size() - 1; j++) {
            if (knnDetails->getTrainVectors()->at(i).getDistance() > knnDetails->getTrainVectors()->at(j + 1).getDistance()) {
                StructVec temp = knnDetails->getTrainVectors()->at(i);
                knnDetails->getTrainVectors()->at(i) = knnDetails->getTrainVectors()->at(j + 1);
                knnDetails->getTrainVectors()->at(j + 1) = temp;
            }
        }
    }
}

/******************
* Function Name: findName
* Input: no input
* Output: return the name that appeared the most times (in the first k).
* Function Operation: find the name that appears the most times in the first k structVec.
* ******************/
string Classify::findName() {
    string name;
    map<string, int> kDistances;
    //add all the distances to the map
    for (size_t i = 0; i < stoi(knnDetails->getK()); i++) {
        name = knnDetails->getTrainVectors()->at(i).getName();
        if (kDistances.empty()) { kDistances[name] = 1; }
        auto it = kDistances.find(name);
        if (it != kDistances.end()) {
            it->second = it->second + 1;
        } else { kDistances[name] = 1; }
    }

    //find the max
    string maxName;
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

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: classifies the testVectors according to the knn algorithm and the classifications in trainVectors.
* ******************/
void Classify::execute() {
    if((knnDetails->getTestVectors())->empty() || (knnDetails->getTrainVectors())->empty()){
        dio->write("please upload data");
        return;
    }
    char *distance = new char[(knnDetails->getDistanceMetric()).length() + 1];
    strcpy(distance, (knnDetails->getDistanceMetric()).c_str());
    auto *dis = whatDis(distance);

    //loop that calls the functions that operate the knn algorithm.
    for (int i = 0; i<knnDetails->getTestVectors()->size(); i++) {
        vector<double> temp = (knnDetails->getTestVectors()->at(i).getVector());
        calcDis(dis,knnDetails->getTestVectors()->at(i).getVector());
        sortDistances();
        knnDetails->getTestVectors()->at(i).setName(findName());
    }
    dio->write("complete data classifying");
    knnDetails->setIsClassified(true);
}

/**
 * destructor.
 **/
Classify::~Classify() {}



/*class display*/

/******************
* Function Name: Display
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Display::Display(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "4. display results";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: sends to the client the classifications of the testVectors.
* ******************/
void Display::execute() {
    //if the user didn't upload the data
    if((knnDetails->getTestVectors())->empty() || (knnDetails->getTrainVectors())->empty()){
        dio->write("please upload data");
        return;
    }
    //if the user didn't classify the data
    if(!knnDetails->getIsClassified()){
        dio->write( "data the classify please");
        return;
    }

    int counter = 1;
    string counterString;
    string output;
    int i;
    for (i = 0; i<knnDetails->getTestVectors()->size(); i++){
        counterString = to_string(counter);
        output= counterString+"\t"+ knnDetails->getTestVectors()->at(i).getName();
        dio->write(output);
        counter++;
    }
    dio->write("Done.");
}

/**
 * destructor.
 **/
Display::~Display() {}



/*class download*/

/******************
* Function Name: Download
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Download::Download(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "5. download results";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: write into a file given from the user all the classifications of the testVectors.
* ******************/
void Download::execute() {
    //if the user didn't upload the data
    if((knnDetails->getTestVectors())->empty() || (knnDetails->getTrainVectors())->empty()){
        dio->write("please upload data");
        return;
    }
    //if the user didn't classify the data
    if(!knnDetails->getIsClassified()){
        dio->write("data the classify please");
        return;
    }

    int counter = 1;
    string counterString;
    string output;
    int i;
    for (i = 0; i<knnDetails->getTestVectors()->size(); i++){
        counterString = to_string(counter);
        output= counterString+"\t"+ knnDetails->getTestVectors()->at(i).getName();
        dio->write(output);
        counter++;
    }
    dio->write("Done.");
}

/**
 * destructor.
 **/
Download::~Download() {}



/*class exit*/

/******************
* Function Name: Exit
* Input: pointer to the commands defaultIO and a pointer to the object that contains all the knn details
* Output: no output
* Function Operation: constructor.
* ******************/
Exit::Exit(DefaultIO *&_dio, KnnDetails *&_knn): Command(_dio, _knn) {
    description = "8. exit";
}

/**
 * default implementation for execute of the command class
 **/
void Exit::execute() {}

/**
 * destructor.
 **/
Exit::~Exit() {}