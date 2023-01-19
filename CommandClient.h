//
// Created by adi on 1/19/23.
//

#ifndef CLIENT_COMMANDCLIENT_H
#define CLIENT_COMMANDCLIENT_H
#include <string>
#include "DefaultIO.h"
using namespace std;

class CommandClient {
protected:
    string description;
    DefaultIO * dio;
public:
    CommandClient(DefaultIO *_dio);
    string getDescription() const;
    virtual void execute() = 0;
    ~CommandClient();
};

class UploadData: public CommandClient{
public:
    UploadData(DefaultIO *&_dio);
    void execute() override;
    ~UploadData();
};

class AlgoSettings: public CommandClient{
public:
    AlgoSettings(DefaultIO *&_dio);
    void execute() override;
    ~AlgoSettings();
};

class Classify: public CommandClient{
public:
    Classify(DefaultIO *&_dio);
    void execute() override;
    ~Classify();
};

class Display: public CommandClient{
public:
    Display(DefaultIO *&_dio);
    void execute() override;
    ~Display();
};

class Download: public CommandClient{
public:
    Download(DefaultIO *&_dio);
    void execute() override;
    ~Download();
};


#endif //CLIENT_COMMANDCLIENT_H
