/*
 William Lin
 CSCI 2226
 Program 4
 */

#ifndef Queue_hpp
#define Queue_hpp

#include "Cell.hpp"

class Queue{

    friend class Sorter;
    
private:
    Cell* head = new Cell("", 0, 0);
    Cell* tail = head;
    Cell* scan = nullptr;
    Cell* follow = nullptr;
    int count = 0;
    
public:
    Queue() = default;
    int size(){ return count; }
    bool isempty(){ return count == 0; }
    ~Queue();
    void insert(string text, unsigned long time, float temp);
    void print(ostream& out);
    void clear();
    void concat(Queue q);
};

#endif /* Queue_hpp */
