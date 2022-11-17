#include "VectorArithmetic.h"
#include <iostream>
int main(){
 vector<double> num1 {1, 2, 3, 4, 5};
 vector<double> num2 {1, 2, 3, 4, 5};
 vector<double> num3= addVectors(num1,num2);

  cout << "Initial Vector: ";

  for (const double& i : num3) {
   std:: cout << i << "  ";
  }
}