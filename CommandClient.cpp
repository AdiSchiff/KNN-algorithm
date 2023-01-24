/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "CommandClient.h"
#include <string>
#include <sstream>

/******************
* Function Name: CommandClient
* Input: DefaultIO
* Output: no output
* Function Operation:constructor.
* ******************/
CommandClient::CommandClient(DefaultIO *_dio): dio(_dio) {}

/******************
* Function Name: getDescription
* Input: no input
* Output: string description
* Function Operation: return the description.
* ******************/
string CommandClient::getDescription() const {
    return this->description;
}

/**
 * destructor.
 **/
CommandClient::~CommandClient() {}

/*class uploadData*/

/******************
* Function Name: UploadData
* Input: pointer to the commands defaultIO
* Output: no output
* Function Operation: constructor.
* ******************/
UploadData::UploadData(DefaultIO *&_dio): CommandClient(_dio) {
    description = "1";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: receive to paths and send them line by line.
* ******************/
void UploadData::execute() {
    int i;
    string filePath, output, line;
    fstream file;
    for(i=0; i<2; i++) {
        output = dio->read();
        cout << output << endl;
        getline(cin, filePath);
        //cin >> filePath;
        file.open(filePath);
        if (!file.is_open()) {
            cout << "invalid input" << endl;
            dio->write("error");
            return;
        }
        while (getline(file, line)) {
            dio->write(line);
        }
        dio->write("finish");
        file.close();
        output = dio->read();
        cout << output << endl;
    }
}

/**
 * destructor.
 **/
UploadData::~UploadData() {}



/*class algoSetting*/

/******************
* Function Name: AlgoSettings
* Input: pointer to the commands defaultIO
* Output: no output
* Function Operation: constructor.
* ******************/
AlgoSettings::AlgoSettings(DefaultIO *&_dio): CommandClient(_dio) {
    description = "2";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: send a string of a k and a new distance metric.
* ******************/
void AlgoSettings::execute() {
    string s;
    s = dio->read();
    cout << s << endl;
    getline(cin, s);
    if(s.empty()){
        s = "empty";
    }
    dio->write(s);
    s = dio->read();
    if(s != "finish"){
        cout << s << endl;
    }
}

/**
 * destructor.
 **/
AlgoSettings::~AlgoSettings() {}



/*class classify*/

/******************
* Function Name: Classify
* Input: pointer to the commands defaultIO
* Output: no output
* Function Operation: constructor.
* ******************/
Classify::Classify(DefaultIO *&_dio): CommandClient(_dio) {
    description = "3";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: tell the server to classify the data.
* ******************/
void Classify::execute() {
    string output = dio->read();
    cout << output << endl;
}

/**
 * destructor.
 **/
Classify::~Classify() {}



/*class display*/

/******************
* Function Name: Display
* Input: pointer to the commands defaultIO
* Output: no output
* Function Operation: constructor.
* ******************/
Display::Display(DefaultIO *&_dio): CommandClient(_dio) {
    description = "4";
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: print to the user the classifications of the testVectors.
* ******************/
void Display::execute() {
    string line;
    while(true){
        line = dio->read();
        cout << line << endl;
        if(line == "Done." || line == "data the classify please" || line == "please upload data"){
            break;
        }
    }
}

/**
 * destructor.
 **/
Display::~Display() {}



/*class download*/

/******************
* Function Name: Download
* Input: pointer to the commands defaultIO
* Output: no output
* Function Operation: constructor.
* ******************/
Download::Download(DefaultIO *&_dio): CommandClient(_dio) {
    description = "5";
}

/******************
* Function Name: printToFile
* Input: string of the vectors and the file's path
* Output: no output
* Function Operation: print the classification into a file.
* ******************/
void Download::printToFile(string output, string filePath){
    ofstream file;
    file.open(filePath);
    file<<output<<endl;
    file.close();
}

/******************
* Function Name: execute
* Input: no input
* Output: no output
* Function Operation: receive the classifications of the testVectors and call a function that print them into a file.
* ******************/
void Download::execute() {
    string filePath, line, output;
    while(true){
        line = dio->read();
        if(line == "please upload data" || line == "data the classify please"){
            cout<<line<<endl;
            return;
        }
        if(line == "Done."){
            break;
        }
        output += line;
        output += '\n';
    }
    ofstream file;
    getline(cin, filePath);
    file.open(filePath);
    if(!file){
        cout<<"invalid input"<<endl;
        return;
    }
    file.close();
    thread downloadThread(&Download::printToFile, output, filePath);
    downloadThread.detach();
}

/**
 * destructor.
 **/
Download::~Download() {}