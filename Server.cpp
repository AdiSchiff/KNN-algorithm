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
#include "ReceiveVector.h"
#include "DefaultIO.h"
#include "StandardIO.h"
#include "Command.h"
#include "Cli.h"
#include "Data.h"
#include "Distance.h"
#include "Minkowski.h"
#include "EuclideanDistance.h"
#include "ManhattanDistance.h"
#include "ChebyshevDistance.h"
#include "CanberraDistance.h"
using namespace std;

/******************
Function Name:whatDis
Input: string dis = the name of the distance function we need to use.
Output: no output
Function Operation: return a distance object according to the distance function given as an argument.
******************/
Distance *whatDis(const char *dis) {
   if (strcmp(dis, "AUC") == 0) {
       auto *ed = new EuclideanDistance();
       return ed;
   }
   if (strcmp(dis, "MAN") == 0) {
       auto *mad = new ManhattanDistance();
       return mad;
   }
   if (strcmp(dis, "CHB") == 0) {
       auto *chd = new ChebyshevDistance();
       return chd;
   }
   if (strcmp(dis, "CAN") == 0) {
       auto *cad = new CanberraDistance();
       return cad;
   }
   if (strcmp(dis, "MIN") == 0) {
       auto *mid = new Minkowski();
       return mid;
   }
   else {
       return NULL;
   }
}

int main(int argc, char **argv)
{
    const int server_port= stoi(argv[2]);
    //validation check for the port
    if (!isdigit(*argv[2]) || stoi(argv[2]) < 0 || stoi(argv[2]) > 65535) {
        cout<<"invalid port argument"<<endl;
        exit(0);
    }
    int sock= socket(AF_INET, SOCK_STREAM,0);
    if (sock<0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock,(struct sockaddr*)&sin, sizeof(sin))<0)
    {
        perror("error binding socket");
    }
    if (listen(sock,5)<0)
    {
        perror("error listening to a socket");
    }

    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        DefaultIO* dio = new StandardIO;
        Cli *cli = new Cli(dio);
        cli->start();
        close(client_sock);
    }
    close(sock);
    return 0;
 }