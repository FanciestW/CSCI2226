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
    friend class Sorter;
    
private:
    string text;
    unsigned long time;
    float temp;
    Cell* next;
    Cell(string txt, unsigned long t, float tem, Cell* nx = nullptr) : text(txt), time(t), temp(tem), next(nx){}
};

#endif /* Cell_hpp */
