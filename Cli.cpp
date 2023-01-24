//
// Created by adi on 1/17/23.
//

#include <cstring>
#include "Cli.h"
#include "Command.h"
#define SIZE_OF_MENU 7

Cli::Cli(DefaultIO *&_dio, KnnDetails *&_knn): dio(_dio), knnDetails(_knn) {}

void Cli::start() {
    Command *ptr0 = new Welcome(dio, knnDetails);
    Command *ptr1 = new UploadData(dio, knnDetails);
    Command *ptr2 = new AlgoSettings(dio, knnDetails);
    Command *ptr3 = new Classify(dio, knnDetails);
    Command *ptr4 = new Display(dio, knnDetails);
    Command *ptr5 = new Download(dio, knnDetails);
    Command *ptr8 = new Exit(dio, knnDetails);
    Command *menu[SIZE_OF_MENU] = {ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr8};
    int i;
    string s;
    string invalid = "invalid input";
    while(true) {
        for (i = 0; i < SIZE_OF_MENU; i++) {
            dio->write(menu[i]->getDescription());
        }
        s = dio->read();
        if(s == "empty"){
            dio->write(invalid);
            continue;
        }
        char *c = new char[s.length()+1];
        strcpy(c,s.c_str());
        if(!isdigit(*c)){
            dio->write(invalid);
            continue;
        }
        i = stoi(s);
        if (i>0 && i<6) {
            menu[i]->execute();
        } else if(i == 8) {
            break;
        } else {
            dio->write(invalid);
        }
    }
}
