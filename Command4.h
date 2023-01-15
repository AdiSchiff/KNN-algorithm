//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMAND4_H
#define CLIENT_COMMAND4_H
#include "Command.h"
#include "DefaultIO.h"

using namespace std;

class Command4: public Command{
private:
    string const description = "display results";
    DefaultIO dio;
public:
    explicit Command4(DefaultIO dio);
    void execute() override;
    ~Command4();
};


#endif //CLIENT_COMMAND4_H
