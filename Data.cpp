
#include "Data.h"
StructVec createStructVector(string line){



    string name="";
    string tempVec="";
    string vecString="";
    string temp="";
    for(char c:line){
        if (c==',')
        {
            temp+= " ";
            tempVec.append(temp);
            temp="";
        }else{
            temp.append(c);
        }
    }
    int i=0;
    for(i<(tempVec.size()-1); i++){
        vecString+=tempVec[i];
    }
    name.append(temp);
    StructVec sv;
    sv.StructVec(vecString, name);
    return sv;
}
    


