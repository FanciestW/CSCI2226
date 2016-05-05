/*
 William Lin
 CSCI 2226
 Program 4
 */

#ifndef Sorter_hpp
#define Sorter_hpp

#include "Queue.hpp"

class Sorter{
    
private:
    Queue mQ;
    Queue bucket[256];
    
public:
    Sorter(Queue q){ mQ = q; }
    void printmQ(ostream& out){ mQ.print(out); }
    void filePrint(string fileName);
    void sort();
    void distribute(int k);
    void collect();
    unsigned long getTempAsUnsigned(float* pcurrTemp);
};

#endif
