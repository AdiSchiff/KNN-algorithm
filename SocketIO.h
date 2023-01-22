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
