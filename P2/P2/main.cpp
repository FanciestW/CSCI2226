#include "Tally.hpp"

int main(){
    banner();
    string fileName;
    cout << "File Name: ";
    cin >> fileName;
    ifstream input = ifstream( fileName );
    Tally tally = Tally( input );
    tally.doTally();
    tally.pretty();
    bye();
}
