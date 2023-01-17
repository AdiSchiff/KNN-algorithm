//
// Created by adi on 1/12/23.
//

#ifndef CLIENT_COMMA_H
#define CLIENT_COMMA_H
#include <string>
#include "DefaultIO.h"
using namespace std;


class Command {
protected:
    string description;
    DefaultIO * dio;
public:
    Command(DefaultIO *_dio);
    string getDescription() const;
    virtual void execute() = 0;
    ~Command();
};

class Welcome: public Command{
public:
    Welcome(DefaultIO *&_dio);
    void execute() override;
    ~Welcome();
};

class UploadData: public Command{
public:
    UploadData(DefaultIO *&_dio);
    void execute() override;
    ~UploadData();
};

class AlgoSettings: public Command{
public:
    AlgoSettings(DefaultIO *&_dio);
    void execute() override;
    ~AlgoSettings();
};

class Classify: public Command{
public:
    Classify(DefaultIO *&_dio);
    void execute() override;
    ~Classify();
};

class Display: public Command{
public:
    Display(DefaultIO *&_dio);
    void execute() override;
    ~Display();
};

class Download: public Command{
public:
    Download(DefaultIO *&_dio);
    void execute() override;
    ~Download();
};

class Exit: public Command{
public:
    Exit(DefaultIO *&_dio);
    void execute() override;
    ~Exit();
};

#endif //CLIENT_COMMA_H
