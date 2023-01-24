/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef CLIENT_CLI_H
#define CLIENT_CLI_H
#include "DefaultIO.h"
#include "KnnDetails.h"


class Cli {
private:
    DefaultIO* dio;
    KnnDetails* knnDetails;
public:
    Cli(DefaultIO *&_dio, KnnDetails *&_knn);
    void start();
};


#endif //CLIENT_CLI_H
