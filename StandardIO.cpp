//
// Created by adi on 1/15/23.
//

#include "StandardIO.h"

string StandardIO::read()const{
    string input;
    cin >> input;
    return input;
}

void StandardIO::write(string s) const {
    cout<<"bye"<<endl;
    cout<< s <<endl;
}

StandardIO::~StandardIO() {}
