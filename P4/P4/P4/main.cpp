/*
 William Lin
 CSCI 2226
 Program 4
 */

#include "Sorter.hpp"
#include <string>

unsigned long getTime(string line);
float getTemp(string line);
Queue sortTemp(Queue q, int k);

int main(int argc, const char * argv[]) {
    
    banner();
    string fileName;
    Queue masterQ = *new Queue();
    ifstream input("sensor_01.txt");
    
    if(input.is_open()){
        
        for(;;){
            string line;
            getline(input, line);
            masterQ.insert(line, getTime(line), getTemp(line));
            if(input.eof()) break;
        }
        
    } else cout << "File Error" << endl;
    
    Sorter sorter(masterQ);
    sorter.sort();
    
    bye();
    
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