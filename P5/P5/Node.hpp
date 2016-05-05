#ifndef Node_hpp
#define Node_hpp

#include "Tally.hpp"

class Node{
    
    typedef Node* tree;
    friend class Heap;
    
private:
    char c;
    int freq;
    Node *left, *right;
    
public:
    Node() = default;
    ~Node() = default;
    Node(char c, int freq):c(c), freq(freq){}
    Node(Node *tleft, Node *tright):left(tleft), right(tright){
        c = '\n';
        freq = tleft->freq + tright->freq;
    }
    void print(ostream& out);
};

#endif /* Node_hpp */