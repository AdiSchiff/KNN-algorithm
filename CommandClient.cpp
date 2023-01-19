//
// Created by adi 3on 1/19/23.
//

#include "CommandClient.h"
#include "iostream"
#include <fstream>
#include <string.h>

CommandClient::CommandClient(DefaultIO *_dio) {}

string CommandClient::getDescription() const {
    return this->description;
}

CommandClient::~CommandClient() {}

/*class uploadData*/
UploadData::UploadData(DefaultIO *&_dio): CommandClient(_dio) {
    description = "1";
}

void UploadData::execute() {
    int i;
    string filePath = 0, output = 0, line = 0;
    fstream file;
    for(i=0; i<2; i++) {
        output = dio->read();
        cout << output << endl;
        cin >> filePath;
        file.open(filePath);
        if (!file.is_open()) {
            cout << "Error! can't open file" << endl;
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
    return;
}

UploadData::~UploadData() {}

/*class algoSetting*/
AlgoSettings::AlgoSettings(DefaultIO *&_dio): CommandClient(_dio) {
    description = "2";
}

void AlgoSettings::execute() {
    string s;
    s = dio->read();
    cout << s << endl;
    cin >> s;
    dio->write(s);
    s = dio->read();
    if(s.compare( "finish")){
        cout << s << endl;
    }
    return;
}

AlgoSettings::~AlgoSettings() {}

/*class classify*/
Classify::Classify(DefaultIO *&_dio): CommandClient(_dio) {
    description = "3";
}

void Classify::execute() {
    string output = dio->read();
    cout << output << endl;
}

Classify::~Classify() {}

Display::Display(DefaultIO *&_dio): CommandClient(_dio) {
    description = "4";
}

void Display::execute() {
    string line;
    while(true){
        line = dio->read();
        cout << line << endl;
        if(line.compare("Done.")){
            break;
        }
    }
    return;
}

Display::~Display() {}

Download::Download(DefaultIO *&_dio): CommandClient(_dio) {
    description = "5";
}

void Download::execute() {
    string filePath, line;
    fstream file;
    cin >> filePath;
    ofstream File("classified.csv");
    while(true){
        line = dio->read();
        if(line.compare("Done.")){
            break;
        }
        File << line;
    }
    File.close();
    return;
}

Download::~Download() {}