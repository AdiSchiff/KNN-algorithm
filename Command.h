//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H
#include <string>
#include "DefaultIO.h"
using namespace std;


class Command {
private:
    string const description;
    DefaultIO const dio;
public:
    string getDescription() const { return this->description;}
    DefaultIO getDio() const {return this->dio;}
    virtual void execute() const = 0;
};


#endif //CLIENT_COMMAND_H
