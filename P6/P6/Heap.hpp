#ifndef Heap_hpp
#define Heap_hpp

#include "Node.hpp"
#include <map>

class Heap{
    
    
private:
    Tally tally;
    
public:
    std::map<char, string> map;
    vector<Node*> vect;
    Heap() = default;
    Heap(Tally tally);
    void    insert( Node* key );
    Node*   remove();
    void	heapSort();
    void	printHeap();
    void    printTree(Node* node, string space);
    void    printNode(Node* node);
    void    buildHeap();
    void    downHeap(int pos, Node* key);
    void    upHeap(int pos, Node* key);
    void    push(Node* node);
    void    pop();
    void    reduceHeap();
};

#endif /* Heap_hpp */
