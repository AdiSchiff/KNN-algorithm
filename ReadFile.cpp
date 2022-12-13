/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "ReadFile.h"

vector <StructVec> createStructVector(string filePath){
    vector <StructVec> structVec;

    fstream file;
    file.open(filePath);
    if(!file.is_open()){
        cout << "Error! can't open file" << endl;
        exit(0);
    }
    string line;
    while (getLine(file,line))
    {
           structVec.insert(createStructVector(line));
    }
    file.close(); 
    return structVec;
}
