//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMA_H
#define CLIENT_COMMA_H
#include <string>
#include "DefaultIO.h"
#include "KnnDetails.h"
#include "ReceiveVector.h"
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