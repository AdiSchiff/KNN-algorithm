//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND4_H
#define CLIENT_COMMAND4_H
#include "Command.h"
using namespace std;

class Command4: public Command{
private:
    string const description = "display results";
public:
    void execute() const override;

};


#endif //CLIENT_COMMAND4_H
