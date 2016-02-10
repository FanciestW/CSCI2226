#include "tools.hpp"

class Tally {
    
private:
    int tal[256];
    int inCount;
    ifstream& input;
    
public:
    Tally( ifstream& input):input(input){ }
    void doTally();
    void print();
    void pretty();
};
