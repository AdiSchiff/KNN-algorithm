//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND5_H
#define CLIENT_COMMAND5_H
#include "Command.h"
using namespace std;

class Command5: public Command{
private:
    string const description = "download results";
    DefaultIO dio;
public:
    explicit Command5(DefaultIO dio);
    void execute() override;
    ~Command5();
};


#endif //CLIENT_COMMAND5_H
