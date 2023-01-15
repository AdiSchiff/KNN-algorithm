//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_MENU_H
#define CLIENT_MENU_H
#include "Command.h"
using namespace std;


class Command1: public Command{
private:
    string const description = "1. upload an unclassified csv data file";
    DefaultIO dio;
public:
    explicit Command1(const DefaultIO& dio);
    void execute() override;
~Command1();
};


#endif //CLIENT_MENU_H
