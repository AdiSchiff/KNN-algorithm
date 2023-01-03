/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef CHEBYSHEVDISTANCE_H_
#define CHEBYSHEVDISTANCE_H_

#include "Distance.h"
#include <vector>

using namespace std;

class ChebyshevDistance : public Distance {
    double distance(vector<double> v1, vector<double> v2) override;
};

#endif
