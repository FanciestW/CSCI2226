#include "tools.hpp"

#ifndef Tally_hpp
#define Tally_hpp

class Tally {
    
private:
    int inCount;
    ifstream& input;
    
public:
    int tal[256];
    Tally( ifstream& input ):input( input ){ }
    void doTally();
    void print();
    void pretty();
};

#endif
