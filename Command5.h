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
public:
    void execute() const override;

};


#endif //CLIENT_COMMAND5_H
