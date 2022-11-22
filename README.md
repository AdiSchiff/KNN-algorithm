
**Name**
Calculating distances between two vectors

**Description**
The program will receive a line of numbers separated by a space.
After that it will get another line of numbers separated by a space.
The program will return all the distances in order with line drop separation.

The distances are:
-EuclideanDistance: https://en.wikipedia.org/wiki/Euclidean_distance
-ManhattanDistance: https://en.wikipedia.org/wiki/Taxicab_geometry
-ChebyshevDistance: https://en.wikipedia.org/wiki/Chebyshev_distance
-CanberraDistance: https://en.wikipedia.org/wiki/Canberra_distance
-MinkowskiDistance: https://en.wikipedia.org/wiki/Minkowski_distance

MinkowskiDistance- define p as 2.

**Implementation**
The program  receives 2 numbers from the user and checks the currectness of the input
- Negative or positive numbers (integer/ double)
- The vectors must be in the same size
- No spaces or special character are allowed
If the input is incorrect it will be returned to the user: "Illegal input" and exit the program.
In addition, the program converts the input into 2 vectors calculates and prints the 5 distances 
which are explained above.
- If the user enter more than 1 space between 2 numbers the input will be accepted: the same as if there 
was only one space.
- If the  user will enter a space before the first digit/ minus or after the last digit the program will 
print "Illegal input"

VectorArithmetic.cpp- calculating of all arithmetic operations between vectors.
Print.cpp- printing the distances
Distances.cpp- calculating the distances according to the formulas
ReceiveVector- conversion of the input and vertification of correctness


**Dependencies**
- g++ compiler

#Installing And Executing
First to run the program you need to install git on your computer.
(In this link: https://github.com/AdiSchiff/Idit-Adi.git )

Open the command line and follow the following commands:
- Clone repository:git clone -----------
- Go into the repository: cd Idit-Adi
-`g++ -std=c++11 *.cpp`
-`./a.out`



**Authors**
Idit Medizada- github username:IditMedizada 
Adi Schiff- github username: AdiSchiff