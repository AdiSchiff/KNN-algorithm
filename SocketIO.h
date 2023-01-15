#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include "DefaultIO.h"
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class SocketIO: public DefaultIO 
{
private:
    int clientSocket;
public:
    SocketIO(int socket);
    ~SocketIO();
    string read() override;
    void write(string s) override;
};



#endif 
