#include "Tally.hpp"

void Tally::doTally(){
    for(;;){
        char c;
        if(input.eof()) break;
        input.get(c);
        tal[(int)c]++;
    }
}

void Tally::print(){
    for(int k = 0; k < 256; k++){
        cout << tal[k] << endl;
    }
}

//Prints easy to read results
void Tally::pretty(){
    for(int k = 0; k < 256; k++){
        cout << (char)k << ": " << tal[k] << endl;
    }
}