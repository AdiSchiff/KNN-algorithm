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
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command8.h"
#include "Command0.h"

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
    Command0 command;
    Command& command0 = command;
    Command* command1 = Command1;
    Command* command2 = Command2;
    Command* command3 = Command3;
    Command* command4 = Command4;
    Command* command5 = Command5;
    Command* command8 = Command8;

    Command** menu [command0, command1, command2, command3, command4, command5, command8];
    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }

        while(true) {
            int i;
            for(i = 0; i<7; i++){
                menu[i].getDio().wright(menu[i].getString());
            }
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            memset(buffer,0,sizeof (buffer));

            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if(buffer[0] == '-' && buffer[1] == '1' && read_bytes == 2){
                //close the connection with the current client
                close(client_sock);
                break;
            }
            if (read_bytes == 0) {
                //wait to receive input from the client
            } else if (read_bytes < 0) {
                // error
            } else {
                string output;
                auto data = new Data();
                auto *rv = new ReceiveVector();
                vector<StructVec> *structVec = data->initializeStructVec(argv[1]);
                string *userInput = data->getData(buffer, read_bytes);
                const char *knn = userInput[2].c_str();
                //check the legality of the KNN value
                if (!isdigit(*knn) || stoi(userInput[2]) < 0) {
                    output = "invalid input";
                } else {
                    char *distance = new char[userInput[1].length() + 1];
                    strcpy(distance, userInput[1].c_str());
                    auto *dis = whatDis(distance);
                    //if the distance metric was invalid
                    if (dis == NULL) {
                        output = "invalid input";
                    } else {
                        vector<double> v1 = rv->transferStringToVector(userInput[0]);
                        //if the input vector was invalid
                        if (v1.at(0) == NULL) {
                            output = "invalid input";
                        } else {
                            data->calcDis(dis, v1);
                            //if the input vector wasn't at the same size as the vectors at the file
                            if (structVec->at(0).getDistance() == NULL) {
                                output = "invalid input";
                            } else {
                                //if the knn value is bigger then the number of vectors in the file
                                if (stoi(userInput[2]) > structVec->size() - 1) {
                                    output = "invalid input";
                                } else {
                                    data->sortDistances(stoi(userInput[2]));
                                    output = data->findName(stoi(userInput[2]));
                                }
                            }
                        }
                    }
                }
                char *data_addr = new char[output.length() + 1];
                strcpy(data_addr, output.c_str());
                int data_len = strlen(data_addr);
                int sent_bytes = send(client_sock, data_addr, data_len, 0);
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }

        }
    }
    close(sock);
    return 0;
 }