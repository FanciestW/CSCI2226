/*
 William Lin
 CSCI 2226
 Program 4
 */

#include "Sorter.hpp"

void Sorter::sort(){
    for(int k = 0; k < 4; k++){
        distribute(k);
        collect();
    }
    ofstream out("text.txt");
    mQ.print(out);
}

void Sorter::distribute(int k){
    unsigned char mask = 0xff;
    mQ.scan = mQ.head->next;
    for(;mQ.scan != nullptr;){
        int n = 8 * k;
        float currTemp = mQ.scan->temp;
        unsigned long currTempAsUns = getTempAsUnsigned(&currTemp);
        int subscript = mask & (currTempAsUns >> n);
        bucket[subscript].insert(mQ.scan->text, mQ.scan->time, mQ.scan->temp);
        mQ.scan = mQ.scan->next;
        mQ.head->next = mQ.scan;
        mQ.count--;
    }
    mQ.tail = mQ.head;
}

void Sorter::collect(){
    for(int k = 0; k < 256; k++){
        mQ.concat(bucket[k]);
        bucket[k].clear();
    }
}

unsigned long Sorter::getTempAsUnsigned(float* pCurrTemp){
    return *(unsigned long*) pCurrTemp;
}