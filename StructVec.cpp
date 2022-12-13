
#include "StructVec.h"
class StructVec
{
private:
    vector<double>vec;
    string name;
    double distance;
public:
    StructVec(vector<double> vec1 ,string name1) {
        vec=vec1;
        name=name1;
        distance=0;
    }
};


