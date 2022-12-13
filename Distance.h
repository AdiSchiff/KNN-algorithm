/*
Ex 1 part 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#ifndef DISTANCE_H_
#define DISTANCE_H_
#include <vector>
#include <iostream>
#include <cmath>
#include <vector>
#include "VectorArithmetic.h"
using namespace std;

public class Distance
{
public:
    double euclideanDistance(vector <double> v1, vector <double> v2);
    double manhattanDistance(vector <double> v1, vector <double> v2);
    double chebyshevDistance(vector <double> v1, vector <double> v2);
    double canberraDistance(vector <double> v1, vector <double> v2);
    double minkowskiDistance(vector <double> v1, vector <double> v2, int p);
    ~Distance();
};

#endif