/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#include <sys/socket.h>
#include <cstdio>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "DefaultIO.h"
#include "SocketIO.h"
#include "CommandClient.h"

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

    DefaultIO* dio = new SocketIO(sock);
    CommandClient *ptr0 = new UploadData(dio);
    CommandClient *ptr1 = new AlgoSettings(dio);
    CommandClient *ptr2 = new Classify(dio);
    CommandClient *ptr3 = new Display(dio);
    CommandClient *ptr4 = new Download(dio);
    CommandClient *menu[5] = {ptr0, ptr1, ptr2, ptr3, ptr4};
    int i;
    string s, input;
    while(true) {
        for (i = 0; i < 7; i++) {
            s = dio->read();
            cout << s << endl;
        }
        getline(cin, input);
        if(input.empty()){
            input = "empty";
        }
        dio->write(input);
        char *c = new char[input.length()+1];
        strcpy(c,input.c_str());
        if(isdigit(*c)) {
            i = stoi(input);
            if (i > 0 && i < 6) {
                menu[i - 1]->execute();
            } else if (i == 8) {
                break;
            } else {
                input = dio->read();
                cout<<input<<endl;
            }
        } else {
            input = dio->read();
            cout << input << endl;
        }
    }
    close(sock);// if 8 close and break
    return 0;
}
