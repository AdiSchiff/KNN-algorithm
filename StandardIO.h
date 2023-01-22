//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_STANDARDIO_H
#define CLIENT_STANDARDIO_H
#include <iostream>
#include "DefaultIO.h"
using namespace std;

class StandardIO: public DefaultIO{
public:
    string read()const override;
    void write(string s) const override;
    ~StandardIO();
};


#endif //CLIENT_STANDARDIO_H
