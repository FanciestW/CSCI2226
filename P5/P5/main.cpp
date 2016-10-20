#include "Heap.hpp"

int main(){
    banner();

    ifstream input = ifstream( "text.txt" );
    if(!input.is_open()) fatal("Error");
    cout << "input opened" << endl;
    
    Tally tally(input);
    cout << "New Tally object named tally created" << endl;
    
    tally.doTally();
    cout << "doTally() Completed on tally" << endl;

    Heap heap(tally);
    cout << "New Heap created with tally" << endl;
    
    heap.buildHeap();
    cout << "buildHeap() Completed" << endl;
    
    for(int k = 0; k < 8; k++){
        heap.reduceHeap();
        cout << "reduceHeap(" << k << ")" << endl;
    }
    
    heap.printTree(heap.vect[1], "");
    cout << "printTree Completed on heap.vect[1]" << endl;

    input.close();
    cout << "input closed" << endl;
    
    bye();
}