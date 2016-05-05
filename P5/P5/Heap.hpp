#ifndef Heap_hpp
#define Heap_hpp

#include "Node.hpp"

class Heap{
    
private:
    vector<Node*> vect;
    Tally tally;
    void	downHeap( int start, Node* key );
    void	upHeap( int start, Node* key  );
    void	heapify();
    
public:
    Heap() = default;
    Heap( Tally tally);
    void    insert( Node* key );
    Node*   remove();
    void	heapSort();
    void	printHeap();
    void    buildHeap();
    void    push(Node* node);
    void    pop();
    
};

#endif /* Heap_hpp */
