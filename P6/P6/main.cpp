#include "Heap.hpp"
#include "bitOutStream.hpp"

int main(){
    banner();

    ifstream input = ifstream( "test.txt" );
    if(!input.is_open()) fatal("Error");
//    cout << "input opened" << endl;
    
    Tally tally(input);
//    cout << "New Tally object named tally created" << endl;
    
    tally.doTally();
//    cout << "doTally() Completed on tally" << endl;

    Heap heap(tally);
//    cout << "New Heap created with tally" << endl;
    
    heap.buildHeap();
//    cout << "buildHeap() Completed" << endl;
    
    for(int k = 0; k < 8; k++){
        heap.reduceHeap();
//        cout << "reduceHeap(" << k << ")" << endl;
    }
    
    heap.printTree(heap.vect[1], "");
//    cout << "printTree Completed on heap.vect[1]" << endl;k
    
    ofstream output("output.txt");
    BitOutStream bitOut(output);
    bitOut.createCode(heap.vect[1], "");
    bitOut.printCode();
    bitOut.insertCode();
    
    
    input.close();
    output.close();
//    cout << "input closed" << endl;
    
    bye();
}