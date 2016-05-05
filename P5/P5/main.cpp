#include "Heap.hpp"

int main(){
    banner();
    ifstream input = ifstream( "text.txt" );
    if(input.is_open()){
        Tally tally = *new Tally(input);
        tally.doTally();
        tally.pretty();
        Heap heap = *new Heap(tally);
        heap.printHeap();
        heap.buildHeap();
        heap.printHeap();
    } else cout << "Error" << endl;
    bye();
}