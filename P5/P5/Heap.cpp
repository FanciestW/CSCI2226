#include "Heap.hpp"


Heap::Heap( Tally tally ):tally(tally){
    push(new Node('\n', 0));
    for(int k = 0; k < 256; k++){
        if(tally.tal[k] != 0){
            push(new Node((char)k, tally.tal[k])); //Adds Tally to Heap
        } 
    }
}

/*
 Acts as heapify, takes the vector and makes sure it is a heap
 */
void Heap::buildHeap(){
    int k, leafPos, ok;
    Node* temp;
    
    for(k = 1; k < vect.size(); k++){
        ok = 0;
        leafPos = k;
        while((leafPos > 1) && !ok){
            int parent = floor(leafPos/2);
            if(vect.at(leafPos)->freq < vect.at(parent)->freq){
                temp = vect.at(leafPos);
                vect.at(leafPos) = vect.at(parent);
                vect.at(parent) = temp;
                leafPos = parent;
            } else ok = 1;
        }
    }
}

//TODO: Change print to print tree.
/*
 Prints the heap based on frequency only
 */
void Heap::printHeap(){
    for(int k = 0; k < vect.size(); k++){
        cout << vect.at(k)->freq;
    }
    cout << endl;
}

/*
 Adds a node to end of the heap
 */
void Heap::push(Node *node){
    vect.push_back(node);
}

/*
 Removes the last node of the heap
 */
void:: Heap::pop(){
    vect.erase(vect.end());
}