#include "Heap.hpp"

int main(){
    banner();
    ifstream input = ifstream( "text.txt" );
    if(input.is_open()){
        Tally tally = *new Tally(input);
        tally.doTally();
        tally.pretty();
        Heap heap = *new Heap(tally);
        heap.buildHeap();
        for(int k = 0; k < 8; k++){
            heap.reduceHeap();
        }
    } else cout << "Error" << endl;
    bye();
}