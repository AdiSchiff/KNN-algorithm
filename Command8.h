//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND8_H
#define CLIENT_COMMAND8_H
#include "Command.h"
using namespace std;

class Command8: public Command{
private:
    string const description = "exit";
public:
    void execute() const override;

};


#endif //CLIENT_COMMAND8_H
