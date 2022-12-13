/*
Ex 1 part 2
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "Print.h"

/******************
Function Name:printDistance
Input: double distance
Output: void function
Function Operation: prints the distance in the appropriate format
******************/
void printDistance(double distance){
    // Checks if the distance is an integer
    //The distance will be printed in the following format: distance.0
    if(floor(distance) - ceil(distance) == 0)
        printf("%.1f\n", distance);
    else{
        //If it is a floating point- prints 16 digits after the point
        printf("%.16f\n", distance);
    }
}

/******************
Function Name:printAll
Input: vector<double> v1,vector<double> v2
Output:void function
Function Operation: The function receive 2 vectors and sends to print the distances
obtained from the 5 other functions(distances functions)
******************/
void printAll(vector <double> v1, vector <double> v2){

    printDistance(euclideanDistance(v1,v2));
    printDistance(manhattanDistance(v1,v2));
    printDistance(chebyshevDistance(v1,v2));
    printDistance(canberraDistance(v1,v2));
    printDistance(minkowskiDistance(v1,v2,2));
}


