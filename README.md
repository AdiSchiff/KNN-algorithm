
**Name**
connection server-client
K-nearest-neighbors (KNN) algorithm

**Description**
The program is divided into two parts
Client side - receives a vector and distance from the user and sends to the server
Server side - receives the information from the client, calculates the K nearest neighbors of the vector and returns the appropriate classification to the client
The server checks which of the vectors are tagged in the database closest to the vector we received from the user.
Then, it takes the K vectors most similar to the input and classifies the vector according to the most common label.

**Implementation**
1. The client gets  the ip and port number of the server.
2. The client receives a vector and distance from the user and sends to the server.
3. If the vector is incorrect, an error message is returned to the client and the client waits to another input from the user.(Details on input integrity is below).
4. The server gets all the information from the clients and calculate the K nearest neighbors of the vector according to the last project (ex2)
5. The server returns  the classification of the vector to the client and the client prints it.

**More about the implementation-- ex2**
1. The server reads the file line by line, divides each line to vector and name and enter them to struct vector
(class with 3 members- vector, name and distance).
2. Checking the distances between all the vectors in a database to the vector we received from the user according to 
the distance metric we receive from the argv. (Base on ex1).
3. Select algorithm on all the distances. find the  K vectors most similar to the input.
4. The program puts the K distances into map <string, int>.
string- is the classification name
int- number of times that the classification is in the K distances.
5. find the max value in the map and save the appropriate key.

**Validation**

-The vectors must be in the same size no spaces or special character are allowed.
If the input is incorrect it will be returned to the user: "invalid input" and exit the program

- K value must be a positive number, less than the number of vectors in the file. Else,t will be returned to the user:
"invalid input" and exit the program

- distance- only 5 strings in upercase letters(like below).t will be returned to the user:"invalid input" and exit.

- Ip number- must be in that format XXXX.XXXX.XXXX.XXXX  (X:0-9)   
for example: 127.0.0.1 localhost   
- port number must be in the range of 0-65,535

**Dependencies**
- g++ compiler   
**Installing And Executing**   
-First to run the program you need to install git on your computer.    
-Open the command line and follow the following commands:  
`git clone -b main3 https://github.com/AdiSchiff/Idit-Adi.git`   
`cd Idit-Adi`     
`make`    
`Server.out  file path portNumber` (for example Server.out  datasets/iris/iris_classified.csv 12345).    
`Client.out portNumber ipNumber` (for example Cerver.out 127.0.0.1 12345).      

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
