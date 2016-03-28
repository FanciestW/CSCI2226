/*
 William Lin
 CSCI 2226
 Program 4
 */

#include "Queue.hpp"

Queue::~Queue(){
    
    for(;;){
        scan = head;
        if(scan == NULL) break;
        head = head->next;
        delete scan;
    }
    
}

void Queue::print(ostream& out){
    out << "---------------\n";
    scan = head->next; //skips the dummy header
    while(scan != nullptr){
        out << scan->time << ", " << scan->temp << endl;
        scan = scan->next;
    }
    out << "================\n";
}

void Queue::remove(unsigned long time){
    find(time);
    if(scan == nullptr || scan->time != time)
        cout << endl << time << " is not in the list.\n\n";
    else{
        --count;
        if(follow == nullptr){
            head = head->next;
            delete scan;
        }
        else{
            follow->next = scan->next;
            delete scan;
        }
    }
}

void Queue::insert(unsigned long time, float temp){
    Cell *cell = new Cell(time, temp);
    tail->next = cell;
    tail = cell;
    count++;
}

void Queue::find(unsigned long time){
    if(count < 0) cout << "Error" << endl;
    else{
        scan = head->next;
        while(scan != nullptr){
            if(scan->time == time) break;
            else scan = scan->next;
        }
    }
}

void Queue::sort(int n){
    Queue bucket[256];
    char mask = 0xff;
    scan = head->next;
    follow = head;
    for(int k = 0; k < count; k++){
        unsigned currTemp = scan->temp;
        int subscript = mask & (currTemp >> 8 * n);
        bucket[subscript].insert(this->head->time, head->temp);
        follow = scan;
        scan = scan->next;
        this->remove(follow->time);
    }
    for(int i = 0; i < 256; i++){
        bucket[i].print(cout);
    }
}