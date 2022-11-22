// #include "VectorArithmetic.h"
// #include "Distance.h"
#include "Print.h"
#include <iostream>
#include <vector>
#include "ReceiveVector.h"
using namespace std;

int main(){
vector<double> v1 = receiveVector();
vector<double> v2 = receiveVector();
  if(v1.size() != v2.size()){//if the vectors don't have the same number of elements
    cout << "ilegal input";
    exit(0);
}
  printAll(v1,v2);
}
