//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND3_H
#define CLIENT_COMMAND3_H
#include "Command.h"
using namespace std;

class Command3: public Command{
private:
    string const description = "classify data";
    DefaultIO dio;
public:
    explicit Command3(DefaultIO dio);
    void execute() override;
    ~Command3();
};


#endif //CLIENT_COMMAND3_H
