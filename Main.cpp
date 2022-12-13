// #include "VectorArithmetic.h"
// #include "Distance.h"
#include "Print.h"
#include <iostream>
#include <vector>
#include "ReceiveVector.h"
#include "ReadFile.h"
using namespace std;


int main(int argc, char** argv){
vector<double> v1 = receiveVector();
vector<StructVec> structVec = createStructVector(argv[3]);



//   if(v1.size() != v2.size()){//if the vectors don't have the same number of elements
//     cout << "ilegal input";
//     exit(0);
// }
//   printAll(v1,v2);
}