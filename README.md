
# Threads - connection server-client
### K-nearest-neighbors algorithm (using commands design pattern)   

#### Description and Implementation     
In this exercise our server will have to handle several clients at the same time. At a given moment, the server can speak
with several different clients at the same time.
When a client connects to the server, the server will send the client a text detailing (a menu) the server's function.
The client will print to the screen the text received from the server.

The server must send the following text to the client:    
Welcome to the KNN Classifier Server. please choose an option:   
1- upload an unclassified csv data file   
2- algorithm settings   
3- classify data    
4- display results   
5- download results   
8- exit   

**option 1**   
If the user typed 1 and enter, the user will be given the option to type a path to his local csv file.
After pressing enter, the client will send the contents of the file to the server. At the end of sending, the server will send
"complete Upload" message. If the path is invalid will be printed "input invalid" and return to the menu. 
This process will be repeated twice, when the first time you receive a file for training the classifier and the second time a file for his exam. 

**option 2**  
The server will send the current classifier parameter values which is the K parameter value and the current distance matric.  
If the user presses enter, we will leave the data unchanged. Otherwise, the user will enter new values where K can take a range of integer values and the distance metric can take the values we saw in the previous exercise. If everything is fine - return to the main menu.
If the user entered an invalid value - the error message will be returned as required and we will return to the menu(invalid value for metric/k)   

**option 3**  
The server will run the KNN algorithm on thr files that uploaded by the client.
At the end of the run, the server will write "complete data classifying" and we will return to the main menu. If no files have been uploaded yet, print "please upload data".

**option 4**  
The server will return the list of classifications in the following format:   
1 A
2 B
.
.
Done   
where C, B, A are the classification classes.   
If no files have been uploaded yet, print "please upload data." If the files to be printed have not yet been classified print "please classify the data."  

**option 5**  
Writing the results from option 4 to the file entered by the user (using threads)  

**option 8**    
Termination of client-server communication. The server will continue to accept other clients



#### Validation

1. The vectors must be in the same size no spaces or special character are allowed.
2. K value must be a positive number, less than the number of vectors in the file. Else,the server will return "invalid value for k"  and return to the menu  
3. If the user tries to change the value of K before files have been uploaded, an error message will be returned (it is impossible to know if the value is valid)
4. Distance metric- only 5 strings in upercase letters(AUC,MAN,MIN,CAN,CHB).Else, the serverf will return "invalid value for metric" and return to the menu  
5. Ip number- must be in that format XXXX.XXXX.XXXX.XXXX  (X:0-9) for example: 127.0.0.1 localhost   
6. port number must be in the range of 0-65,535
7. In case the routing of the files is incorrect, an error message is printed to the client and the menu will be printed 
8. The server and the client must enter a port/IP number during configuration (Ip-client only)  

#### Dependencies
- g++ compiler   
#### Installing And Executing 
First to run the program you need to install git on your computer.      
Open the command line and follow the following commands:    
`git clone -b main4 https://github.com/AdiSchiff/Idit-Adi.git`   
`cd Idit-Adi`    
open 2 terminals:    
1. Server   
`make`    
`./server.out  portNumber` (for example ./server.out  12345).   
2. Client   
`make`    
`./client.out ipNumber portNumber` (for example ./client.out 127.0.0.1 12345).        
 

#### Authors
Idit Medizada- github username:IditMedizada        
Adi Schiff- github username: AdiSchiff
