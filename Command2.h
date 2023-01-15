//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND2_H
#define CLIENT_COMMAND2_H
#include "Command.h"
using namespace std;

class Command2: public Command{
private:
    string const description = "algorithm settings";
    DefaultIO dio;
public:
    explicit Command2(DefaultIO dio);
    void execute() override;
    ~Command2();
};


#endif //CLIENT_COMMAND2_H
