//
// Created by adi on 1/17/23.
//

#include <cstring>
#include "Cli.h"
#include "Command.h"
#define SIZE_OF_MENU 7

Cli::Cli(DefaultIO *&_dio): dio(_dio) {}

void Cli::start() {
    Welcome *ptr0 = new Welcome(dio);
    UploadData *ptr1 = new UploadData(dio);
    AlgoSettings *ptr2 = new AlgoSettings(dio);
    Classify *ptr3 = new Classify(dio);
    Display *ptr4 = new Display(dio);
    Download *ptr5 = new Download(dio);
    Exit *ptr8 = new Exit(dio);
    Command *menu[SIZE_OF_MENU] = {ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr8};
    int i;
    string s;
    string invalid = "invalid input";
    while(true) {
        for (i = 0; i < SIZE_OF_MENU; i++) {
            dio->write(menu[i]->getDescription());
        }
        s = dio->read();
        char *c = new char[s.length()+1];
        strcpy(c,s.c_str());
        if(!isdigit(*c)){
            dio->write(invalid);
            continue;
        }
        i = stoi(s);
        if (i>0 && i<6) {
            menu[i]->execute();
        }
        if(i == 8) {
            break;
        } else {
            dio->write(invalid);
        }
    }
}

/*while(true) {
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

}*/