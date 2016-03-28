/*
 William Lin
 CSCI 2226
 Program 4
 */

#include "Queue.hpp"
#include <string>

unsigned long getTime(string line);
float getTemp(string line);
Queue sortTemp(Queue q, int k);

int main(int argc, const char * argv[]) {
    
    banner();
    string fileName;
    Queue masterQ = *new Queue();
    cout << "File Name: ";
    cin >> fileName;
    ifstream input(fileName);
    
    if(input.is_open()){
        
        for(;;){
            string line;
            getline(input, line);
            if(input.eof()) break;
            masterQ.insert(getTime(line), getTemp(line));
        }
        
    } else cout << "File Error" << endl;
    
    masterQ.print(cout);
    cout << string(50, '-') << endl;
    masterQ.sort(0);
    
}

unsigned long getTime(string line){
    unsigned long time = stoi(line.substr(27, 10));
    return time;
}

//Converts temp from C to Kalvin and returns in K
float getTemp(string line){
    float temp = stof(line.substr(44));
    return temp + 273.15;
}