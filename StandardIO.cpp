//
// Created by adi on 1/15/23.
//

#include "StandardIO.h"

string StandardIO::read()const{
    string input;
    getline(cin, input);
    return input;
}

void StandardIO::write(string s) const {
    cout<< s <<endl;
}

StandardIO::~StandardIO() {}
