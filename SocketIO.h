/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include "DefaultIO.h"
#include <sys/socket.h>
#include <string>
#include <cstring>

using namespace std;

class SocketIO: public DefaultIO {
private:
    int clientSocket;
public:
    explicit SocketIO(int socket);
    string read() const override;
    void write (string) const override;
    ~SocketIO();
};


#endif 
