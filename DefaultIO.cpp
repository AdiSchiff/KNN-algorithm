//
// Created by adi on 1/15/23.
//
#include <string>
#include <iostream>
#include "DefaultIO.h"
string DefaultIO::read() const{};
void DefaultIO::write(string) const{
    cout<<"hi"<<endl;
}

/*DefaultIO::~DefaultIO() {

};*/
