#ifndef Heap_hpp
#define Heap_hpp

#include "Node.hpp"

class Heap{
    
private:
    vector<Node*> vect;
    Tally tally;
    
public:
    Heap() = default;
    Heap( Tally tally);
    void    insert( Node* key );
    Node*   remove();
    void	heapSort();
    void	printHeap();
    void    buildHeap();
    void    downHeap(int pos, Node* key);
    void    upHeap(int pos, Node* key);
    void    push(Node* node);
    void    pop();
    void    reduceHeap();
};

#endif /* Heap_hpp */
