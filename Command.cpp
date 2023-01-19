//
// Created by adi on 1/15/23.
//
#include "Command.h"

/*class command*/
string Command::getDescription() const {
    return this->description;
}
Command::Command(DefaultIO *_dio) : dio(_dio){}

Command::~Command() {}

/*class welcome*/
Welcome::Welcome(DefaultIO *&_dio): Command(_dio){
    description = "Welcome to the KNN Classifier Server. please choose an option:";
}

void Welcome::execute() {}

Welcome::~Welcome() {}

/*class uploadData*/
UploadData::UploadData(DefaultIO *&_dio): Command(_dio) {
    description = "1. upload an unclassified csv data file";
}

void UploadData::execute() {}

UploadData::~UploadData() {}

/*class algoSetting*/
AlgoSettings::AlgoSettings(DefaultIO *&_dio): Command(_dio) {
    description = "algorithm settings";
}

void AlgoSettings::execute() {}

AlgoSettings::~AlgoSettings() {}

/*class classify*/
Classify::Classify(DefaultIO *&_dio): Command(_dio) {
    description = "classify data";
}

void Classify::execute() {}

Classify::~Classify() {}

Display::Display(DefaultIO *&_dio): Command(_dio) {
    description = "display results";
}

void Display::execute() {}

Display::~Display() {}

Download::Download(DefaultIO *&_dio): Command(_dio) {
    description = "download results";
}

void Download::execute() {}

Download::~Download() {}

Exit::Exit(DefaultIO *&_dio): Command(_dio) {
    description = "exit";
}

void Exit::execute() {}

Exit::~Exit() {}
