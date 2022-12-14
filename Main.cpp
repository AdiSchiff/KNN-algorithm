/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#include <iostream>
#include <vector>
#include "ReceiveVector.h"
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
        cout << "illegal distance metric" << endl;
        exit(0);
    }
}

int main(int argc, char **argv) {
    if(argc != 4){
        cout << "illegal number of arguments in the configuration" << endl;
        exit(0);
    }
    if (!isdigit(*argv[1]) || stoi(argv[1]) < 0) {
        cout << "illegal KNN value" << endl;
        exit(0);
    }
    auto data = new Data();
    vector<StructVec> *structVec = data->initializeStructVec(argv[2]);
    auto *dis = whatDis(argv[3]);
    auto *rv = new ReceiveVector();
    while (true) {
        vector<double> v1 = rv->receiveVector();
        data->calcDis(dis, v1);
        data->sortDistances(stoi(argv[1]));
        cout << data->findName(stoi(argv[1])) << endl;
    }
}

