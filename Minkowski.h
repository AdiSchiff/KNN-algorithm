/*
Ex 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef MINKOWSKI_H_
#define MINKOWSKI_H_

#include "Distance.h"
#include <vector>

using namespace std;

class Minkowski : public Distance {
public:
    double distance(vector<double> v1, vector<double> v2) override;
};

#endif
