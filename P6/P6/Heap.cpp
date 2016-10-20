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
 Acts as heapify, takes the vector and puts it in heap order
 */
void Heap::buildHeap(){
    int leaf = (int)vect.size()/2;
    for(int k = leaf; k > 0; k--){
        downHeap(k, vect[k]);
//        cout << k << " completed" << endl;
    }
}

void Heap::downHeap( int start, Node* key ) {
//    cout << "downHeap(" << start << ", vect[" << start << "])" << endl;
    int father = start;	int son, rson;
    for (;;) {
        son = 2*father;
        rson = son + 1;
        if (son >= vect.size()){
//            cout << "End of tree" << endl;
            break;  // This is off the end of the tree.
        }
        if (rson <= vect.size() && vect[son]->freq > vect[rson]->freq){
            son = rson;
//            cout << "son = rson" << endl;
        }
        if ( key->freq <= vect[son]->freq ){
//            cout << "break" << endl;
            break;
        }
        vect[father] = vect[son];
        father = son;
//        cout << "father and son swap" << endl;
    }
//    cout << "downHeap() loop finished" << endl;
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
    for(int k = 0; k < vect.size(); k++){         if(isprint((int)vect[k]->c)) cout << vect[k]->freq << ": " << vect[k]->c << "| ";
        else cout << vect[k]->freq << ": " << (int)vect[k]->c << "| ";
    }
    cout << endl;
}

void Heap::printTree(Node* currNode, string space){
    if(currNode->right != nullptr){
        printTree(currNode->right, space + "    ");
    }
    cout << space;
    printNode(currNode);
    if(currNode->left == nullptr) cout << "----";
    cout << endl;
    if(currNode->left != nullptr) printTree(currNode->left, space + "    ");
    cout << endl;
}

void Heap::printNode(Node* node){
    if(isprint(node->c)) cout << node->c << ": " << node->freq;
    else cout << (int)node->c << ": " << node->freq;
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