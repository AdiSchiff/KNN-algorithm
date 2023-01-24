/*
Ex 4
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/
#ifndef CLIENT_COMMA_H
#define CLIENT_COMMA_H
#include <string>
#include "DefaultIO.h"
#include "KnnDetails.h"
#include "StructVec.h"
#include "ReceiveVector.h"
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "ManhattanDistance.h"
#include "Minkowski.h"
#include "EuclideanDistance.h"
#include <map>
using namespace std;


class Command {
protected:
    string description;
    DefaultIO * dio;
    KnnDetails * knnDetails;
public:
    Command(DefaultIO *_dio, KnnDetails *_knn);
    string getDescription() const;
    virtual void execute() = 0;
    ~Command();
};

class Welcome: public Command{
public:
    Welcome(DefaultIO *&_dio, KnnDetails *&_knn);
    void execute() override;
    ~Welcome();
};

class UploadData: public Command{
public:
    UploadData(DefaultIO *&_dio, KnnDetails *&_knn);
    static StructVec* createStructVector(const string& line);
    void execute() override;
    ~UploadData();
};

class AlgoSettings: public Command{
public:
    AlgoSettings(DefaultIO *&_dio, KnnDetails *&_knn);
    bool isValidK(const string& k);
    static bool isValidDistance(const string& distance);
    void execute() override;
    ~AlgoSettings();
};

class Classify: public Command{
public:
    Classify(DefaultIO *&_dio, KnnDetails *&_knn);
    void execute() override;
    ~Classify();

    Distance *whatDis(const char *dis);
    void calcDis(Distance *dis, const vector<double> &vec);
    void sortDistances();
    string findName();
};

class Display: public Command{
public:
    Display(DefaultIO *&_dio, KnnDetails *&_knn);
    void execute() override;
    ~Display();
};

class Download: public Command{
public:
    Download(DefaultIO *&_dio, KnnDetails *&_knn);
    void execute() override;
    ~Download();
};

class Exit: public Command{
public:
    Exit(DefaultIO *&_dio, KnnDetails *&_knn);
    void execute() override;
    ~Exit();
};

#endif //CLIENT_COMMA_H