//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMA_H
#define CLIENT_COMMA_H
#include <string>
#include "DefaultIO.h"
using namespace std;


class Command {
private:
    string const description;
    DefaultIO dio;
public:
    string getDescription() const;
    DefaultIO getDio() const;
    virtual void execute() = 0;
    ~Command();
};


#endif //CLIENT_COMMA_H
