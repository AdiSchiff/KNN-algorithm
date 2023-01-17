//
// Created by adi on 1/17/23.
//

#ifndef CLIENT_CLI_H
#define CLIENT_CLI_H
#include "DefaultIO.h"


class Cli {
private:
    DefaultIO* dio;
public:
    Cli(DefaultIO *&_dio);
    void start();
};


#endif //CLIENT_CLI_H
