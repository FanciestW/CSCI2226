/*
 William Lin
 CSCI 2226
 Program 4
 */

#ifndef Cell_hpp
#define Cell_hpp

#include "tools.hpp"

class Cell{
    
    friend class Queue;
    
private:
    unsigned long time;
    float temp;
    Cell* next;
    Cell(unsigned long t, float tem, Cell* nx = nullptr) : time(t), temp(tem), next(nx){}
};

#endif /* Cell_hpp */
