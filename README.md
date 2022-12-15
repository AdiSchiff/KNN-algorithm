
**Name**
K-nearest-neighbors (KNN) algorithm

**Description**
The program will receive 3 arguments from the command line(k,file and distance).
Moreover, it will get a vector from the user.
The program whill check which of the vectors are tagged in the database closest to the vector we received from the user.
Then, it takes the K vectors most similar to the input and classifies the vector according to the most common label.

**Implementation**
1. The program receives a vector and checks its integrity-
If the vector is incorrect, an error message is returned and the program exits.(Details on input integrity is below).
2. Then, the program reads the file line by line, divides each line to vector and name and enter them to struct vector
(class with 3 members- vector, name and distance).
3. Checking the distances between all the vectors in a database to the vector we received from the user according to 
the distance metric we receive from the argv. (Base on ex1).
4. Select algorithm on all the distances. find the  K vectors most similar to the input.
5. The program puts the K distances into map <string, int>.
string- is the classification name
int- number of times that the classification is in the K distances.
6. find the max value in the map and save the appropriate key.
7. The program prints the classification of the vector.

Validation:

-The vectors must be in the same size no spaces or special character are allowed.
If the input is incorrect it will be returned to the user: "Illegal input" and exit the program

- K value must be a positive number, less than the number of vectors in the file. Else,t will be returned to the user:
"Illegal input" and exit the program

- distance- only 5 strings in upercase letters(like below).t will be returned to the user:"Illegal input" and exit.

- argv: if the program gets a number different from 4 (number of args that the program need) we also close the program.


**Dependencies**
- g++ compiler   
**Installing And Executing**   
-First to run the program you need to install git on your computer.    
-Open the command line and follow the following commands:  
`git clone -b tempMainEx2 https://github.com/AdiSchiff/Idit-Adi.git`   
`cd Idit-Adi`
`make`    
`a.out k file distance` (for example a.out 3 iris_classified.csv MAN).

k= number of neighbors.   
file= file classified vectors (relative/ absolut).   
distance= distance metrica (string value).  
AUC-Euclidean distance.   
MAN-Taxicab geometry.  
CHB-Chebyshev distance.   
CAN-Canberra distance.   
MIN-Minkowski distance.   


**Authors**
Idit Medizada- github username:IditMedizada 
Adi Schiff- github username: AdiSchiff
