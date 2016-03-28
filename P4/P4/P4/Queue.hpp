/*
 William Lin
 CSCI 2226
 Program 4
 */

#ifndef Queue_hpp
#define Queue_hpp

#include "Cell.hpp"

class Queue{

private:
    Cell* head = new Cell(0, 0);
    Cell* tail = head;
    Cell* scan = nullptr;
    Cell* follow = nullptr;
    int count = 0;
    
public:
    Queue() = default;
    int size(){ return count; }
    bool isempty(){ return count == 0; }
    ~Queue();
    void find(unsigned long time);
    void insert(unsigned long time, float temp);
    void remove(unsigned long time);
    void print(ostream& out);
    void sort(int n);
};

#endif /* Queue_hpp */
