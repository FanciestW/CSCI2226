#include "tools.hpp"

#ifndef Tally_hpp
#define Tally_hpp

class Tally {
    
    friend class Heap;
    
private:
    int inCount;
    ifstream& input;
    int tal[256];
    
public:
    Tally( ifstream& input ):input( input ){ }
    void doTally();
    void print();
    void pretty();
};

#endif
