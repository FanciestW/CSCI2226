/*
 William Lin
 CSCI 2226
 Program 4
 */

#include "Queue.hpp"

Queue::~Queue(){
    
//    for(;;){
//        scan = head;
//        if(scan == NULL) break;
//        head = head->next;
//        delete scan;
//    }
    
}

void Queue::print(ostream& out){
    scan = head->next; //skips the dummy header
    while(scan != nullptr){
        out << scan->text << endl;
        scan = scan->next;
    }
}

void Queue::insert(string text, unsigned long time, float temp){
    Cell *cell = new Cell(text, time, temp);
    tail->next = cell;
    tail = cell;
    count++;
}

void Queue::clear(){
    head->next = nullptr;
    tail = head;
    count = 0;
}

//TODO: Made sure concat works. It does
void Queue::concat(Queue q){
    if(!q.isempty()){
        tail->next = q.head->next; //TODO: Creates Tail infinite loop
        tail = q.tail;
        count = count + q.count;
    }

}