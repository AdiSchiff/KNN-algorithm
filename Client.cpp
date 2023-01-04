/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    const char* ip_address= argv[1];// server ip address
    int port_no=stoi(argv[2]);// server port
    int sock= socket(AF_INET, SOCK_STREAM,0);// create socket
    if (sock<0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family= AF_INET;
    sin.sin_addr.s_addr= inet_addr(ip_address);
    sin.sin_port= htons(port_no);
    if (connect(sock,(struct sockaddr*)&sin, sizeof(sin))<0) // create connection with the server
    {
        perror("error connecting to server");
        return 0;
    }

    string userInput;
    while(true) {
        // get vector, distance and k.
        getline(cin, userInput);
        const int inputLength=userInput.length();
        char* data_addr= new char  [inputLength+1];
        strcpy(data_addr,userInput.c_str());
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            perror("error sending data");
        }
        //if the user entered "-1" close this client's socket
        if(userInput[0] == '-' && userInput[1] == '1' && data_len == 2){
            break;
        }
        //read from server
        char buffer[4096];
        memset(buffer,0,sizeof (buffer));
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // connection is closed
        } else if (read_bytes < 0) {
            perror("error reading data");
        } else {
            cout << buffer<<'\n'<< flush;
        }
    }
    close(sock);// if -1 close and break
    return 0;
}