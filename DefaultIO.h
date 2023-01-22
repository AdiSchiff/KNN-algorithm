//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_DEFAULTIO_H
#define CLIENT_DEFAULTIO_H
using namespace std;


class DefaultIO {
public:
    virtual string read() const;
    virtual void write (string) const;
    ~DefaultIO();
};


#endif //CLIENT_DEFAULTIO_H
