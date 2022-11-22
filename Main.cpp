#include "VectorArithmetic.h"
#include "Distance.h"
#include <iostream>

int main(){
 vector<double> num1 {1, 2, 3};
 vector<double> num2 {3, 2, 1};
 double d = minkowskiDistance(num1,num2, 2);
 std:: cout << d;
 /*vector<double> num3= addVectors(num1,num2);

  cout << "Initial Vector: ";

  for (const double& i : num3) {
   std:: cout << i << "  ";
  }*/
}
