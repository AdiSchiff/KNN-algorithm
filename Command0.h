//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND0_H
#define CLIENT_COMMAND0_H
#include "Command.h"
using namespace std;

class Command0: public Command{
private:
    string const description = "Welcome to the KNN Classifier Server. please choose an option:";
public:
    void execute() const override;

};


#endif //CLIENT_COMMAND0_H
