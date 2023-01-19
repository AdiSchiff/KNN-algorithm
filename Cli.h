//
// Created by adi on 1/17/23.
//

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
