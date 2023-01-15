//
// Created by adi on 1/15/23.
//

#include "StandardIO.h"

string StandardIO::read(){
    string input;
    cin >> input;
    return input;
}

void StandardIO::write(string s) {
    cout<< s <<endl;
}