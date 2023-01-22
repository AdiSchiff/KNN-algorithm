/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "SocketIO.h"

SocketIO:: SocketIO(int socket): clientSocket(socket){}

string SocketIO:: read() const {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    memset(buffer,0,sizeof (buffer));
    int read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
    // connection is closed
    } else if (read_bytes < 0) {
        perror("error reading data");
    }
    return string(buffer);
}

void SocketIO:: write(string s) const {
    char *data_addr = new char[s.length() + 1];
    strcpy(data_addr, s.c_str());
    int data_len = strlen(data_addr);
    int sent_bytes = send(clientSocket, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}
