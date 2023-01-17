/*
Ex 3
Idit Medizada 318879293
Adi Schiff 212730675
https://github.com/AdiSchiff/Idit-Adi.git
*/

#include "Data.h"

/******************
* Function Name: getData
* Input: buffer that contains the input from the client and the length of this string
* Output: an array that holds the separated strings
* Function Operation:cut the string from the client into separate arguments
* ******************/
string *Data:: getData(char buffer[], int numOfBytes){
auto *userData = new string[3];
string temp;
int i;
//retrieve the vector
for( i=0; i<numOfBytes; i++){
    if(isdigit(buffer[i]) || (buffer[i] == ' ') || (buffer[i] == '.') || (buffer[i] == '-') || (buffer[i] == 'E')) {
        temp+=buffer[i];
    }
    else{
        break;
    }
}
temp.pop_back();// delete the space from the end of the vector
userData[0]=temp;
temp="";
int j;
//retrieve the distance metric
for(j = i; j<numOfBytes; j++){
    if(buffer[j]== ' '){
        break;
    }
    temp+=buffer[j];
}
userData[1]=temp;
temp="";
//retrieve the knn value
for(int k = j+1; k<numOfBytes; k++){
    temp+=buffer[k];
}
userData[2]=temp;
return userData;
}


/******************
* Function Name: createStructVector
* Input: string line
* Output: pointer to StructVec
* Function Operation:create an object of type StructVec and return a pointer of it.
* ******************/
StructVec *Data::createStructVector(string line) {

    string name;
    string tempVec;
    string vecString;
    string temp;
    for (char c: line) {
        if (c == ',') {
            temp += " ";
            tempVec += temp;
            temp = "";
        } else {
            temp += c;
        }
    }
    for (size_t i = 0; i < tempVec.size() - 1; i++) {
        vecString += tempVec[i];
    }
    name.append(temp);
    auto *rv = new ReceiveVector();

    auto *sv = new StructVec(rv->transferStringToVector(vecString), name);
    return sv;
}

/******************
* Function Name: initializeStructVec
* Input: string filePath
* Output: vector<StructVec>
* Function Operation:create a vector of type StructVec and return a pointer of it.
* ******************/
vector<StructVec> *Data::initializeStructVec(string filePath) {
    fstream file;
    file.open(filePath);
    if (!file.is_open()) {
        cout << "Error! can't open file" << endl;
        return nullptr;
    }
    string line;
    while (getline(file, line)) {
        structVec.push_back(*createStructVector(line));
    }
    file.close();
    return &structVec;
}

/******************
* Function Name: calcDis
* Input: pointer of a Distance object and a vector
* Output: no output
* Function Operation:calculate all the distances between the given vector and all the vectors in structVec.
* ******************/
void Data::calcDis(Distance *dis, const vector<double> &vec) {
    for (auto &&v: structVec) {
        v.setDistance(dis->distance(vec, v.getVector()));
    }
}

/******************
* Function Name: sortDistances
* Input: int k
* Output: no output
* Function Operation:sort the first k structVec by their distance value.
* ******************/
void Data::sortDistances(int k) {
    for (size_t i = 0; i < k; i++) {
        for (size_t j = i; j < structVec.size() - 1; j++) {
            if (structVec.at(i).getDistance() > structVec.at(j + 1).getDistance()) {
                StructVec temp = structVec.at(i);
                structVec.at(i) = structVec.at(j + 1);
                structVec.at(j + 1) = temp;
            }
        }
    }
}

/******************
* Function Name: findName
* Input: int k
* Output: return the name that appeared the most times (in the first k).
* Function Operation:find the name that appears the most times in the first k structVec.
* ******************/
string Data::findName(int k) {
    string name;
    //add all the distances to the map
    for (size_t i = 0; i < k; i++) {
        name = structVec.at(i).getName();
        if (kDistances.empty()) { kDistances[name] = 1; }
        auto it = kDistances.find(name);
        if (it != kDistances.end()) {
            it->second = it->second + 1;
        } else { kDistances[name] = 1; }
    }

    //find the max
    string maxName="";
    int maxRepetitions = 0;
    map<string, int>::iterator itr;
    for (itr = kDistances.begin(); itr != kDistances.end(); ++itr) {
        if (itr->second > maxRepetitions) {
            maxRepetitions = itr->second;
            maxName = itr->first;
        }
    }
    kDistances.clear();
    return maxName;
}