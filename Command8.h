//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND8_H
#define CLIENT_COMMAND8_H
#include "Command.h"
#include "DefaultIO.h"
using namespace std;

class Command8: public Command{
private:
    string const description = "exit";
    DefaultIO dio;
public:
    explicit Command8(DefaultIO dio);
    void execute() override;
    ~Command8();
};


#endif //CLIENT_COMMAND8_H
