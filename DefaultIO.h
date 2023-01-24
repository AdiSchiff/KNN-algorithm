/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef CLIENT_DEFAULTIO_H
#define CLIENT_DEFAULTIO_H
#include <string>
using namespace std;


class DefaultIO {
public:
    virtual string read() const;
    virtual void write (string) const;
    ~DefaultIO();
};


#endif //CLIENT_DEFAULTIO_H
