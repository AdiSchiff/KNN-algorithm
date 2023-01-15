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
public:
    void execute() const override;

};


#endif //CLIENT_COMMAND3_H
