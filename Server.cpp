/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "DefaultIO.h"
#include "Cli.h"
#include "SocketIO.h"
#include "KnnDetails.h"
#include <thread>
using namespace std;

/******************
* Function Name: runThread
* Input: the client's socket
* Output: no output
* Function Operation: runs the knn algorithm for a single client.
* ******************/
void runThread(int client_sock){
    DefaultIO* dio = new SocketIO(client_sock);
    KnnDetails* knn = new KnnDetails();
    Cli *cli = new Cli(dio, knn);
    cli->start();
    close(client_sock);
    delete dio;
    delete knn;
    delete cli;
}

int main(int argc, char **argv)
{

    const int server_port= stoi(argv[1]);
    //validation check for the port
    if (!isdigit(*argv[1]) || stoi(argv[1]) < 0 || stoi(argv[1]) > 65535) {
        cout<<"invalid port argument"<<endl;
        exit(0);
    }
    int sock= socket(AF_INET, SOCK_STREAM,0);
    if (sock<0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin{};
    memset(&sin,0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock,(struct sockaddr*)&sin, sizeof(sin))<0)
    {
        perror("error binding socket");
    }
    if (listen(sock,10)<0)
    {
        perror("error listening to a socket");
    }

    while(true) {
        struct sockaddr_in client_sin{};
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            break;
        }
        thread clientThread(&runThread, client_sock);
        clientThread.detach();
    }
    close(sock);
    return 0;
 }