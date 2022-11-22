/*
Ex 1 part 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "VectorArithmetic.h"
#include "Distance.h"
#include "ReceiveVector.h"
#include <vector>
#include <iostream>
using namespace std;
int main(){
 vector<double> v1 = receiveVector();
 vector<double> v2 = receiveVector();
  if(v1.size() != v2.size()){//if the vectors don't have the same number of elements
    cout << "ilegal input";
  exit(0);
  }



}
