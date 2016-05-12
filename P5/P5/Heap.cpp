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

void Heap::downHeap( int start, Node* key ) {
    int father = start;	int son, rson;
    
    for (;;) {
        son = 2*father;
        rson = son + 1;
        if (son > vect.size()) break;        // This is off the end of the tree.
        if (rson <= vect.size() && vect[son]->freq > vect[rson]->freq) son = rson;
        if ( key->freq <= vect[son]->freq ) break;
        vect[father] = vect[son];
        father = son;
    }
    vect[father] = key;
}

void Heap::upHeap(int pos, Node* key){
    int son = pos;
    int father;
    
    while (son>1) {
        father = son/2;
        if ( vect[father] <= key ) break;
        vect[son] = vect[father];
        son = father;
    }
    vect[son] = key;
}

void Heap::printHeap(){
    for(int k = 0; k < vect.size(); k++){
        if(isprint((int)vect[k]->c)) cout << vect[k]->freq << ": " << vect[k]->c << "| ";
        else cout << vect[k]->freq << ": " << (int)vect[k]->c << "| ";
    }
    cout << endl;
}

//TODO: Finish code to print huffman tree of Node* in heap position 1
void Heap::printTree(){
    
}

void Heap::push(Node *node){
    vect.push_back(node);
}

void Heap::pop(){
    vect.at(1) = vect.at(vect.size()-1);
    vect.erase(vect.end()-1);
}

void Heap::reduceHeap(){
    Node* node1 = vect[1];
    pop();
    downHeap(1, vect[1]);
    Node* node2 = vect[1];
    pop();
    downHeap(1, vect[1]);
    Node* finNode = new Node(node1, node2);
    push(finNode);
    upHeap((int)vect.size()-1, finNode);
}